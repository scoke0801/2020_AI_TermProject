#include "Goal_RunAway.h"
#include "../Raven_Bot.h"
#include "../navigation/Raven_PathPlanner.h"
#include "../Raven_Game.h"
#include "../Raven_Map.h"
#include "Messaging/Telegram.h"
#include "..\Raven_Messages.h"
#include "Goal_MoveToPosition.h"

#include "Goal_SeekToPosition.h"
#include "Goal_FollowPath.h"



//------------------------------ Activate -------------------------------------
//-----------------------------------------------------------------------------
void Goal_RunAway::Activate()
{
	// ���� ��ġ�� �̵�
	// ��, �����Լ� ������ ������...
	m_iStatus = active;

	RemoveAllSubgoals();

	Raven_Bot* target_enemy = m_pOwner->GetTargetSys()->GetTarget();
	Vector2D location;
	bool enemy_can_see = TRUE;

	while (enemy_can_see)
	{
		location = m_pOwner->GetWorld()->GetMap()->GetRandomNodeLocation();

		if (!target_enemy->canWalkTo(location))
			enemy_can_see = FALSE;
	}

	m_pOwner->GetPathPlanner()->RequestPathToPosition(location);
	AddSubgoal(new Goal_MoveToPosition(m_pOwner, location));

	//bool canWalkTo(Vector2D) ������������ ���� ��ΰ� ������ �������� �ȸ������� �Ǻ�
}

//------------------------------ Process -------------------------------------
//-----------------------------------------------------------------------------
int Goal_RunAway::Process()
{
	ActivateIfInactive();

	m_iStatus = ProcessSubgoals();

    return m_iStatus;
}
