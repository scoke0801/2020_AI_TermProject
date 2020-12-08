#ifndef RAVEN_RUNAWAY_GOAL_EVALUATOR
#define RAVEN_RUNAWAY_GOAL_EVALUATOR
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   ExploreGoal_Evaluator.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:  class to calculate how desirable the goal of exploring is
//-----------------------------------------------------------------------------

#include "Goal_Evaluator.h"
#include "../Raven_Bot.h"


class RunAwayGoal_Evaluator : public Goal_Evaluator
{
public:

    RunAwayGoal_Evaluator(double bias) :Goal_Evaluator(bias) {}

    double CalculateDesirability(Raven_Bot* pBot);

    void  SetGoal(Raven_Bot* pEnt);

    void RenderInfo(Vector2D Position, Raven_Bot* pBot);
};

#endif