import numpy as np
from acados_template import AcadosOcp, AcadosOcpSolver, acados_ocp_solver 
from typing import List
import matplotlib.pyplot as plt 
import matplotlib.patches as mpatches 
from matplotlib import markers

from dataclasses import dataclass, field
import numpy as np
import casadi as cd 

from plannerbenchmark.generic.planner import Planner, PlannerConfig

from plannerbenchmark.planner.acadosMpc.createMpcSolver import create_mpc_solver


@dataclass
class AcadosMpcConfig(PlannerConfig):
    # Problem setup 
    # workspace 
    # TODO: Read the workspace limits from the experiment config instead
    ws_x: List[float] = field(default_factory=lambda: [-15.0, 15.0])    # m
    ws_y: List[float] = field(default_factory=lambda: [-16.0, 16.0])      # m
    
    robot_min_acc: float = -3.0
    robot_max_acc: float = 3.0
    robot_min_vel: float = -3.0
    robot_max_vel: float = 3.0
    robot_max_yawrate: float = 0.26
    robot_min_yawrate: float = -0.26

    N: int = 20 # horizon length

    # MPC cost terms weights, can be real time param
    w_pos: float = 1.0
    w_input: float = 0.01
    w_coll: float = 0.10


class AcadosMpcPlanner(Planner):
    def __init__(self, exp, **kwargs):
        super().__init__(exp, **kwargs)
        self._config = AcadosMpcConfig(**kwargs)

        # NOTE: Initializing solver on first call to self.computeAction, because self._exp is not updated yet with random obstacles
        self._initialized = False

        self._mpc_feasible = False

    def _init_problem(self):
        # Regenerate solver
        self.acados_ocp_solver = create_mpc_solver(self._config, self._exp)

        # TODO: add option to load pregenerated solver
        
    def dt(self):
        return self._exp.dt()

    def reset(self):
        pass

    def setObstacles(self, obsts, r_body):
        pass

    def setSelfCollisionAvoidance(self, r_body):
        pass

    def setJointLimits(self, limits):
        pass

    def setGoal(self, goal):
        pass

    def concretize(self):
        pass

    def computeAction(self, *args):
        if not self._initialized:
            self._init_problem()
            self._initialized = True
        robot_state_current = np.array(args).flatten() # [x, y , vx, vy]
        # print(f"STATE {robot_state_current}")

        # Force solver initial state to be the current robot state
        self.acados_ocp_solver.constraints_set(0, 'lbx', np.array(robot_state_current))
        self.acados_ocp_solver.constraints_set(0, 'ubx', np.array(robot_state_current))

        if not hasattr(self, "_mpc_x_plan"):
            self._mpc_x_plan = np.tile(np.array(robot_state_current).reshape((-1, 1)), (1, self._config.N))

        if not hasattr(self, "_mpc_u_plan"):
            self._mpc_u_plan = np.zeros((self._exp.n(), self._config.N))

        if self._mpc_feasible:
            x_traj_init = np.concatenate((self._mpc_x_plan[:, 1:], self._mpc_x_plan[:, -1:]), axis=1)
            u_traj_init = np.concatenate((self._mpc_u_plan[:, 1:], self._mpc_u_plan[:, -1:]), axis=1)
        else:
            x_traj_init = np.tile(np.array(robot_state_current).reshape((-1, 1)), (1, self._config.N))
            u_traj_init = self._mpc_u_plan = np.zeros((self._exp.n(), self._config.N))

        for iStage in range(0, self._config.N):
            self.acados_ocp_solver.set(iStage, 'x', x_traj_init[:, iStage])
            self.acados_ocp_solver.set(iStage, 'u', u_traj_init[:, iStage])

        # Call the solver
        status = self.acados_ocp_solver.solve()

        # NOTE: In case of solver infeasibility, keeps previous action.
        if status != 0:     # infeasible 
            # print('acados returned status {} in closed loop iteration.'.format(status))
            self._mpc_feasible = False 
            # use previous action
            return list(self._mpc_u_plan[:, 0]) 

        # Obtain solution
        for iStage in range(0, self._config.N):
            self._mpc_x_plan[:, iStage] = self.acados_ocp_solver.get(iStage, 'x')
            self._mpc_u_plan[:, iStage] = self.acados_ocp_solver.get(iStage, 'u')

        self._mpc_feasible = True 
        robot_control_current = list(self._mpc_u_plan[:, 0])

        # print(f"ACTION {robot_control_current}")
        return robot_control_current



