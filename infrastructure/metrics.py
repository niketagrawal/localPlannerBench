import numpy as np
from numpyFk import numpyFk
import abc

def computeDistances(positions, point):
    return np.linalg.norm(np.add(positions, -point), axis=1)

def computeFks(positions, fks_fun):
    all_fks = []
    for pos in positions.T:
        all_fks.append(np.array(fks_fun(pos)))
    return np.array(all_fks)

class Metric(object):
    def __init__(self, name, measNames, params):
        self._name = name
        self._params = params
        self._measNames = measNames

    @abc.abstractmethod
    def computeMetric(self, data):
        return


class DistanceToPointMetric(Metric):

    def computeMetric(self, data):
        positions = np.stack([data[name] for name in self._measNames])
        point = self._params['point']
        return computeDistances(positions, point)


class MinimumDistanceToPointMetric(Metric):

    def computeMetric(self, data):
        positions = np.stack([data[name] for name in self._measNames])
        point = self._params['point']
        distances =  computeDistances(positions, point)
        return (np.min(distances), np.argmin(distances))


class TimeToReachGoalMetric(Metric):
    def computeMetric(self, data):
        goal = self._params['goal']
        fks = np.stack([data[name] for name in self._measNames[:-1]]).T
        t = data[self._measNames[-1]]
        des_distance = self._params['des_distance']
        distances =  computeDistances(fks, goal)
        indices = np.where(distances < des_distance)
        if indices[0].size == 0:
            return -1, 0
        else:
            return 0, t[np.min(indices)]


class ClearanceMetric(Metric):
    def computeMetric(self, data):
        obstacles = self._params['obstacles']
        m = self._params['m']
        n = self._params['n']
        fks = np.stack([data[name] for name in self._measNames]).T.reshape(-1, n, m)
        minDistances = []
        obstLocations = []
        for obst in obstacles:
            for i_fk in range(n):
                distancesToObst = computeDistances(fks[:, i_fk, :], obst['x']) - obst['r']
                minDistToObst = np.min(distancesToObst)
                minDistances.append(minDistToObst)
                obstLocations.append(obst['x'])
        return {"minDist": min(minDistances)}
        return {
            "minDist": min(minDistances),
            "allMinDist":  minDistances,
            "obstLoc": obstLocations}


class SolverTimesMetric(Metric):
    def computeMetric(self, data):
        interval = self._params['interval']
        t_planning = data[self._measNames[0]]
        if interval == 1:
            return np.mean(t_planning)
        else:
            return np.mean(t_planning[:-(interval-1)].reshape(-1, interval), axis=0)[0]


class PathLengthMetric(Metric):
    def computeMetric(self, data):
        pathLength = 0
        fks = np.stack([data[name] for name in self._measNames]).T
        pathLength = [np.linalg.norm(fks[i] - fks[i-1]) for i in range(1,len(fks))]
        return np.sum(pathLength)


class SuccessMetric(Metric):
    def computeMetric(self, data):
        minClearance = self._params['minClearance']
        reachingFlag = self._params['reachingFlag']
        if reachingFlag < 0:
            return False, "Goal not reached"
        if minClearance < 0:
            return False, "Collision"
        return True, ""