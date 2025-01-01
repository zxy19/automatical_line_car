#include "Planner.h"
#include "Control.h"
#include "DataStorage.h"
#include "PlanStages.h"
#include "Utils.h"
#include <utility>
#include <vector>
#include "debug.h"
unsigned int Planner::nextLeft = 0;
unsigned int Planner::nextRight = 0;

unsigned int Planner::hasDelay = 0;
unsigned int Planner::lastTime = 0;

unsigned int Planner::currentStage = 0;
/**
 * 1:before,2:run,3:after
 */
unsigned int Planner::currentStageProgress = 0;
bool Planner::isPaused = false;
double Planner::outputBias;

int Planner::lastError = 0;
int Planner::lastLastError = 0;

void Planner::calcCommonPid() {
    int kp = data_storage::getData(data_storage::DATA_PID_P);
    int ki = data_storage::getData(data_storage::DATA_PID_I);
    int kd = data_storage::getData(data_storage::DATA_PID_D);
    int baseMotorSpd = data_storage::getData(data_storage::DATA_SPEED_0);
    int biasValue = 0;
    if (Control::GRAY_VALUE_LL) {
        biasValue++;
    }
    if (Control::GRAY_VALUE_L) {
        biasValue++;
    }
    if (Control::GRAY_VALUE_R) {
        biasValue--;
    }
    if (Control::GRAY_VALUE_RR) {
        biasValue--;
    }
    if (Control::GRAY_VALUE_M) {
        biasValue = 0;
    }

    // 计算误差变化量
    int deltaError = biasValue - lastError;
    int deltaDeltaError = deltaError - (lastError - lastLastError);

    // 计算PID控制器的输出增量
    double deltaOutput = kp * deltaError + ki * biasValue + kd * deltaDeltaError;

    // 累加到之前的输出上
    outputBias += deltaOutput;

    // 更新误差值
    lastLastError = lastError;
    lastError = biasValue;

    if (outputBias > 0) {
        Control::setMotor(baseMotorSpd * std::min(outputBias, 100.0) / 100, baseMotorSpd);
    } else {
        Control::setMotor(baseMotorSpd, baseMotorSpd * std::max(outputBias, -100.0) / 100);
    }
}

void Planner::clearPid() {
    lastError = 0;
    lastLastError = 0;
    outputBias = 0;
}

void Planner::init() {
    currentStage = 0;
    currentStageProgress = 0;

    PlanStage::initStages();
    data_storage::setDefaultIfZero(data_storage::DATA_PID_P, 10);
    data_storage::setDefaultIfZero(data_storage::DATA_PID_I, 0);
    data_storage::setDefaultIfZero(data_storage::DATA_PID_D, 0);
    data_storage::setDefaultIfZero(data_storage::DATA_SPEED_0, 100);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_CIRCLE_T, 500);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_OBS_T1, 1000);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_OBS_T2, 1000);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_OBS_T3, 1000);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_OBS_T4, 1000);
    data_storage::setDefaultIfZero(data_storage::DATA_DELAY_START, 1000);
    data_storage::setDefaultIfZero(data_storage::DATA_PARAM_SONIC_THRESHOLD, 40);
}
void Planner::reset() {
    currentStage = 0;
    currentStageProgress = 1;
    pause();
}
void Planner::pause() {
    isPaused = true;
}
void Planner::resume() {
    isPaused = false;
}
void Planner::updateNext(unsigned int t) {
    data_storage::setData(data_storage::DATA_PHASE,currentStageProgress,false);
    data_storage::setData(data_storage::DATA_STAGE,currentStage,false);
    data_storage::setData(data_storage::DATA_PAUSE,isPaused,false);
    
    if(isPaused){
        Control::setMotor(0, 0);
        return;
    }
    if(!PlanStage::runStageCheck(currentStage,currentStageProgress)){
        currentStageProgress++;
        if(currentStageProgress > 3){
            currentStageProgress = 1;
            currentStage++;
        }
    }
}
