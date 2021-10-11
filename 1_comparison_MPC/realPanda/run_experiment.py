#! /usr/bin/python3
import argparse
import csv
import datetime
import time
import os
import shutil
from shutil import copyfile
import numpy as np

from fabricsExperiments.infrastructure.expSetup import ExpSetup
from fabricsExperiments.infrastructure.ros_converter_node import ActionConverterNode
from fabrics.planner import FabricPlanner
from mpc.planner import MPCPlanner

class Experiment(object):

    def __init__(self, setup, mpcSetup, fabricSetup, render=False):
        self._mpcSetup = mpcSetup
        self._fabricSetup = fabricSetup
        self._setup = setup
        self._render = render
        self._mpcPlanner = MPCPlanner(mpcSetup, self._setup.n())
        self._fabricPlanner = FabricPlanner(fabricSetup, self._setup.n())
        self._obsts = self._setup.getObstacles()
        self._mpcPlanner.addObstacles(self._obsts)
        self._mpcPlanner.addJointLimits(self._setup.lowerLimits(), self._setup.upperLimits())
        self._mpcPlanner.addGoal(self._setup.goal())
        #self._fabricPlanner.addObstacles(self._obsts)
        self._fabricPlanner.addJointLimits(self._setup.lowerLimits(), self._setup.upperLimits())
        #self._fabricPlanner.addSelfCollisionAvoidance()
        self._fabricPlanner.addGoal(self._setup.goal())
        self._fabricPlanner.concretize()
        self._rosConverter, self._integratorNode = self._setup.connectRos(self._fabricPlanner)

    def addScene(self):
        for obst in self._setup.obstacles():
            self._env.addObstacle(pos=obst.x(), filename='sphere05red_nocol.urdf')
        self._env.addObstacle(pos=self._setup.goal(), filename="sphere_goal.urdf")

    def run(self, planner='mpc'):
        self._res = self._rosConverter.run()

    def save(self, timeStamp, errFlag, planner='mpc'):
        curPath = os.path.dirname(os.path.abspath(__file__)) + "/results"
        if timeStamp == "":
            folderPath = curPath + "/" + planner
        else:
            folderPath = curPath + "/" + planner + "_" + timeStamp
        print("Saving results to : %s" % folderPath)
        if not os.path.exists(folderPath):
            os.mkdir(folderPath)
        else:
            print("Overwriting %s" % folderPath)
            shutil.rmtree(folderPath)
            os.mkdir(folderPath)
        if errFlag >= 0:
            resFile = folderPath + "/res.csv"
            colNames = [*self._res[0]]
            with open(resFile, 'w') as csvfile:
                writer = csv.DictWriter(csvfile, fieldnames=colNames)
                writer.writeheader()
                for res in self._res:
                    writer.writerow(res)
        self._setup.save(folderPath)
        copyfile(self._fabricSetup, folderPath + "/planner.yaml")

def main():
    parser = argparse.ArgumentParser("Run motion planning experiment")
    parser.add_argument(
        "--caseSetup", "-case", type=str, help="setup file"
    )
    parser.add_argument(
        "--mpcSetup", "-mpc", type=str, help="mpc setup"
    )
    parser.add_argument(
        "--fabricSetup", "-fab", type=str, help="fabric setup"
    )
    parser.add_argument('--output-file', '-o', type=str, default='output', help='Output filename without suffix', metavar='output')
    parser.add_argument('--no-stamp', dest='stamp', action='store_false')
    parser.add_argument('--random-goal', dest='random_goal', action='store_true')
    parser.add_argument('--random-obst', dest='random_obst', action='store_true')
    parser.add_argument('--render', dest='render', action='store_true')
    parser.set_defaults(render=False)
    parser.set_defaults(stamp=True)
    parser.set_defaults(random_goal=False)
    parser.set_defaults(random_obst=False)
    args = parser.parse_args()
    if args.stamp:
        timeStamp = "{:%Y%m%d_%H%M%S}".format(datetime.datetime.now())
    else:
        timeStamp = ""
    setup = ExpSetup(args.caseSetup, randomGoal=args.random_goal, randomObst=args.random_obst)
    thisExp = Experiment(setup, args.mpcSetup, args.fabricSetup, render=args.render)
    # errFlag = thisExp.run(planner='mpc')
    # thisExp.save(timeStamp, errFlag, planner='mpc')
    errFlag = thisExp.run(planner='fabric')
    # thisExp.save(timeStamp, errFlag, planner='fabric')

if __name__ == "__main__":
    main()


