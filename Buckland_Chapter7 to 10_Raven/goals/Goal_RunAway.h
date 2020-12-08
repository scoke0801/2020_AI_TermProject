#ifndef GOAL_RUNAWAY_H
#define GOAL_RUNAWAY_H
#pragma warning (disable:4786)

#include "Goals/Goal_Composite.h"
#include "Raven_Goal_Types.h"

class Raven_Bot;

class Goal_RunAway : public Goal_Composite<Raven_Bot>
{
private:

public:

    Goal_RunAway(Raven_Bot* pOwner) :Goal_Composite<Raven_Bot>(pOwner, goal_run_away) {}

    void Activate();
    int Process();
    void Terminate() { m_iStatus = completed; }

};

#endif
