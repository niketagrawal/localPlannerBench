import yaml
import csv
import gym
import numpy as np

import pointRobot
import pandaReacher
import nLinkReacher

from casadiFk import ForwardKinematics
from obstacle import Obstacle

from fabricsExperiments.infrastructure.motionPlanningGoal import MotionPlanningGoal


class ExperimentIncompleteError(Exception):
    pass


class InvalidInitStateError(Exception):
    pass


class Experiment(object):
    def __init__(self, setupFile):
        self._setupFile = setupFile
        self._required_keys = ["T", "dt", "env", "n", "goal", "initState", "robot_type", "limits", "obstacles", "r_body"]
        self.parseSetup()
        self._fk = ForwardKinematics(robot_type=self.robotType())

    def parseSetup(self):
        with open(self._setupFile, "r") as setupStream:
            self._setup = yaml.safe_load(setupStream)
        self.checkCompleteness()
        self._motionPlanningGoal = MotionPlanningGoal((self._setup["goal"]))
        self._obstacles = []
        if self._setup['obstacles']:
            for obst in self._setup['obstacles']:
                obstData = self._setup['obstacles'][obst]
                self._obstacles.append(Obstacle([float(xi) for xi in obstData['x']], obstData['r']))

    def rBody(self):
        return self._setup['r_body']

    def fk(self, q, n, positionOnly=False):
        return self._fk.getFk(q, n, positionOnly=positionOnly)

    def robotType(self):
        return self._setup['robot_type']

    def n(self):
        return self._setup["n"]

    def T(self):
        return self._setup["T"]

    def dt(self):
        return self._setup["dt"]

    def envName(self):
        return self._setup["env"]

    def obstacles(self):
        return self._obstacles

    def limits(self):
        low = np.array(self._setup["limits"]["low"])
        high = np.array(self._setup["limits"]["high"])
        return low, high

    def initState(self):
        try:
            q0 = np.array([float(x) for x in self._setup["initState"]["q0"]])
            q0dot = np.array([float(x) for x in self._setup["initState"]["q0dot"]])
        except:
            raise InvalidInitStateError("Initial state could not be parsed")
        if q0.size != self.n() or q0dot.size != self.n():
            raise InvalidInitStateError("Initial state of wrong dimension")
        return (q0, q0dot)

    def goal(self):
        return self._motionPlanningGoal

    def env(self):
        return gym.make(self.envName(), n=self.n(), dt=self.dt())

    def shuffleInitConfiguration(self):
        q0_new = np.random.uniform(low=self.limits()[0], high=self.limits()[1])
        self._setup['initState']['q0'] = q0_new.tolist()

    def shuffleObstacles(self):
        self._obstacles = []
        for i in range(self._setup['randomObstacles']['number']):
            pos = np.random.uniform(
                low=self._setup['randomObstacles']['limits']['x']['low'], 
                high=self._setup['randomObstacles']['limits']['x']['high']
            )
            r = float(np.random.uniform(
                low=self._setup['randomObstacles']['limits']['r']['low'], 
                high=self._setup['randomObstacles']['limits']['r']['high']
            ))
            self._obstacles.append(Obstacle(pos, r))

    def shuffle(self, random_obst, random_init, random_goal):
        if random_goal:
            self._motionPlanningGoal.shuffle()
        if random_obst:
            self.shuffleObstacles()
        if random_init:
            self.shuffleInitConfiguration()
        return

    def checkCompleteness(self):
        incomplete = False
        missingKeys = ""
        for key in self._required_keys:
            if key not in self._setup.keys():
                incomplete = True
                missingKeys += key + ", "
        if incomplete:
            raise ExperimentIncompleteError("Missing keys: %s" % missingKeys[:-2])

    def save(self, folderPath):
        self._setup['goal'] = self._motionPlanningGoal.subGoalsDict()
        obstsDict = {}
        obstFile = folderPath + "/obst"
        initStateFilename = folderPath + '/initState.csv'
        for i, obst in enumerate(self._obstacles):
            obstsDict['obst' + str(i)] = obst.toDict()
            obst.toCSV(obstFile + "_" + str(i) + ".csv")
        self._setup['obstacles'] = obstsDict
        with open(folderPath + "/exp.yaml", 'w') as file:
            yaml.dump(self._setup, file)
        self._motionPlanningGoal.toCSV(folderPath)
        with open(initStateFilename, "w") as file:
            csv_writer = csv.writer(file, delimiter=",")
            csv_writer.writerow(self.initState()[0])


if __name__ == "__main__":
    setupFile = "testSetupFiles/test_setup.yaml"
    exp = Experiment(setupFile)
    gymEnv = exp.env()
    q0, q0dot = exp.initState()
    gymEnv.reset(q0, q0dot)
    gymEnv.render()
    input("Press enter to end")
