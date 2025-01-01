#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\PlanStages.h"
#include "Planner.h"
#include <vector>
#ifndef PLAN_STG_H
#define PLAN_STG_H

namespace PlanStage {
class Stage {
  public:
    virtual bool before(unsigned int t);
    virtual bool run(unsigned int t);
    virtual bool after(unsigned int t);
};
void initStages();
bool runStageCheck(int stageIdx,int phase);
extern std::vector<Stage*> stages;
} // namespace Planner

#endif