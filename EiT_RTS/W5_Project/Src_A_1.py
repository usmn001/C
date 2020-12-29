"""
Partitionned EDF using PartitionedScheduler.
"""
from simso.core.Scheduler import SchedulerInfo
from simso.utils import PartitionedScheduler
from simso.schedulers import scheduler
import math
@scheduler("simso.schedulers.P_RM_m")
class P_RM_m(PartitionedScheduler):
    def init(self):
        PartitionedScheduler.init(
            self, SchedulerInfo("simso.schedulers.RM_mono"))

    def packer(self):
        # First Fit
        cpus = [[cpu, 0,0] for cpu in self.processors]
        for task in self.task_list:
            j = 0
            for i, c in enumerate(cpus):
                n = c[2] + 1.0
                if (c[1] + float(task.wcet) / task.period) < (n*(math.pow(2,1/n) - 1)):
                    j = i
                    break
            # Affect it to the task.
            self.affect_task_to_processor(task, cpus[j][0])
            # Update utilization.
            cpus[j][1] += float(task.wcet) / task.period
            cpus[j][2] += 1
        return True