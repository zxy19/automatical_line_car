#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\Planner.h"
#include <vector>
#ifndef PLANNER_H
#define PLANNER_H

namespace Planner {
extern unsigned int nextLeft;
extern unsigned int nextRight;

extern unsigned int hasDelay;
extern unsigned int lastTime;

extern unsigned int currentStage;
/**
 * 1:before,2:run,3:after
 */
extern unsigned int currentStageProgress;
extern bool isPaused;
extern double outputBias;

extern int lastError;
extern int lastLastError;

void calcCommonPid();
void clearPid();
void init();
void updateNext(unsigned int t);
void reset();
void pause();
void resume();
} // namespace Planner

#endif