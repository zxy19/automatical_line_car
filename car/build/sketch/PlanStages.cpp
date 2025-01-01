#line 1 "D:\\study\\automatical_line_car\\car\\PlanStages.cpp"
#include "PlanStages.h"
#include "Control.h"
#include "DataStorage.h"

class StageGoStraight : public PlanStage::Stage {
    int time = 0;
    bool before(unsigned int t) {
        time = t + data_storage::getData(data_storage::DATA_DELAY_START);
        return false;
    }
    bool run(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(baseMotorSpd, baseMotorSpd);
        if (t >= time)
            return false;
        return true;
    }
    bool after(unsigned int t) {
        Planner::clearPid();
        return false;
    }
};

/**
 * 左转弯
 */
class StageTurnLeft : public PlanStage::Stage {
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_L && Control::GRAY_VALUE_LL) {
            return false;
        }
        if (!Control::GRAY_VALUE_M && !Control::GRAY_VALUE_R && !Control::GRAY_VALUE_RR && !Control::GRAY_VALUE_L && !Control::GRAY_VALUE_LL) {
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) {
        // 接触到第一个左转，转法：左轮不动，右轮转动
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(0, baseMotorSpd);

        // 转动到右1检测到线结束
        if (Control::GRAY_VALUE_R) {
            return false;
        }
        return true;
    }
    bool after(unsigned int t) {
        Planner::clearPid();
        return false;
    }
};

/**
 * 左转弯
 */
class StageTurnRight : public PlanStage::Stage {
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_R && Control::GRAY_VALUE_RR) {
            return false;
        }
        if (!Control::GRAY_VALUE_M && !Control::GRAY_VALUE_R && !Control::GRAY_VALUE_RR && !Control::GRAY_VALUE_L && !Control::GRAY_VALUE_LL) {
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(baseMotorSpd, 0);

        if (Control::GRAY_VALUE_L) {
            return false;
        }
        return true;
    }
    bool after(unsigned int t) {
        Planner::clearPid();
        return false;
    }
};

/**
 * 通过十字路口
 */
class StageGoCross : public PlanStage::Stage {
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_M && Control::GRAY_VALUE_L && Control::GRAY_VALUE_R) {
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(baseMotorSpd, baseMotorSpd);
        if (!Control::GRAY_VALUE_M || !Control::GRAY_VALUE_L || !Control::GRAY_VALUE_R) {
            return false;
        }
        return true;
    }
    bool after(unsigned int t) {
        Planner::clearPid();
        return false;
    }
};

/**
 * 红方块区域特判
 */
class StageGoRedBlockArea : public PlanStage::Stage {
    bool inArea = false;
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_M && Control::GRAY_VALUE_L && Control::GRAY_VALUE_R) {
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(baseMotorSpd, baseMotorSpd);
        if (!Control::GRAY_VALUE_M || !Control::GRAY_VALUE_L || !Control::GRAY_VALUE_R) {
            if (inArea)
                return false;
            else
                inArea = true;
        }
        if (inArea)
            if (Control::GRAY_VALUE_M && Control::GRAY_VALUE_L && Control::GRAY_VALUE_R) {
                return false;
            }

        return true;
    }
    bool after(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        Control::setMotor(baseMotorSpd, baseMotorSpd);
        if (!Control::GRAY_VALUE_M || !Control::GRAY_VALUE_L || !Control::GRAY_VALUE_R) {
            Planner::clearPid();
            return false;
        }
        return true;
    }
};
/**
 * 障碍区域特判
 */
class StageObstacleArea : public PlanStage::Stage {
    unsigned int t1 = 0;
    unsigned int t2 = 0;
    unsigned int t3 = 0;
    unsigned int t4 = 0;

    bool before(unsigned int t) {
        if (data_storage::getData(data_storage::DATA_SONIC) < data_storage::getData(data_storage::DATA_PARAM_SONIC_THRESHOLD)) {
            t1 = t + data_storage::getData(data_storage::DATA_PARAM_OBS_T1);
            t2 = t1 + data_storage::getData(data_storage::DATA_PARAM_OBS_T2);
            t3 = t2 + data_storage::getData(data_storage::DATA_PARAM_OBS_T3);
            t4 = t3 + data_storage::getData(data_storage::DATA_PARAM_OBS_T4);
            return false;
        }
        return true;
    }
    bool run(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        if (t < t1) {
            Control::setMotor(0, baseMotorSpd);
        } else if (t < t2) {
            Control::setMotor(baseMotorSpd, baseMotorSpd);
        } else if (t < t3) {
            Control::setMotor(baseMotorSpd, 0);
        } else if (t < t4) {
            Control::setMotor(baseMotorSpd, baseMotorSpd);
        } else if (Control::GRAY_VALUE_L || Control::GRAY_VALUE_R || Control::GRAY_VALUE_M || Control::GRAY_VALUE_LL || Control::GRAY_VALUE_RR) {
            return false;
        }

        return true;
    }
    bool after(unsigned int t) {
        Planner::clearPid();
        return false;
    }
};

/**
 * 进入圆形区域特判
 */
class StageCircleArea : public PlanStage::Stage {
    bool inArea = false;
    bool direction = false;
    unsigned int ts = 0;
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_R && Control::GRAY_VALUE_RR) {
            inArea = true;
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) {
        if (inArea) {
            int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
            Control::setMotor(0, baseMotorSpd);
            if (!Control::GRAY_VALUE_R || !Control::GRAY_VALUE_RR) {
                inArea = false;
            }
        } else {
            if (Control::GRAY_VALUE_R && Control::GRAY_VALUE_L) {
                direction = true;
            } else if (Control::GRAY_VALUE_R && Control::GRAY_VALUE_RR) {
                direction = false;
            } else if (Control::GRAY_VALUE_L && Control::GRAY_VALUE_LL) {
                direction = true;
            } else {
                Planner::calcCommonPid();
                return true;
            }
            ts = t + data_storage::getData(data_storage::DATA_PARAM_CIRCLE_T);
            return false;
        }

        return true;
    }
    bool after(unsigned int t) {
        int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
        if (t < ts) {
            if (direction) {
                Control::setMotor(baseMotorSpd, 0);
            } else {
                Control::setMotor(0, baseMotorSpd);
            }
            return true;
        }
        return false;
    }
};

class StageStop : public PlanStage::Stage {
    bool before(unsigned int t) {
        if (Control::GRAY_VALUE_M && Control::GRAY_VALUE_L && Control::GRAY_VALUE_R) {
            return false;
        }
        Planner::calcCommonPid();
        return true;
    }
    bool run(unsigned int t) { return false; }
    bool after(unsigned int t) {
        return false;
    }
};

void PlanStage::initStages() {
    stages.push_back(new StageGoStraight());
    stages.push_back(new StageTurnLeft());
    stages.push_back(new StageGoCross());
    stages.push_back(new StageTurnLeft());
    stages.push_back(new StageGoCross());
    stages.push_back(new StageTurnLeft());
    stages.push_back(new StageGoCross());
    stages.push_back(new StageGoRedBlockArea());
    stages.push_back(new StageTurnRight());
    stages.push_back(new StageObstacleArea());
    stages.push_back(new StageTurnRight());
    stages.push_back(new StageCircleArea());
    stages.push_back(new StageTurnLeft());
    stages.push_back(new StageStop());
}
bool PlanStage::runStageCheck(int stageIdx,int phase){
    PlanStage::Stage *stage = PlanStage::stages[stageIdx];
    if(phase == 1) return stage->before(Planner::currentStageProgress);
    if(phase == 2) return stage->run(Planner::currentStageProgress);
    if(phase == 3) return stage->after(Planner::currentStageProgress);
    return false;
}

std::vector<PlanStage::Stage*> PlanStage::stages;