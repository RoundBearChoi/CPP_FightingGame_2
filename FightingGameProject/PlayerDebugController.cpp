#include "PlayerDebugController.h"


namespace RB::PlayerDebug
{
	PlayerDebugController::PlayerDebugController()
	{

	}

	PlayerDebugController::~PlayerDebugController()
	{

	}

	void PlayerDebugController::Init()
	{
		iPlayerController* pc = ControllerGroup::FindController<iPlayerController>();

		_vecPlayers.push_back(pc->GetPlayerOnPlayerIndex(1));
		_vecPlayers.push_back(pc->GetPlayerOnPlayerIndex(2));
	}

	void PlayerDebugController::OnUpdate()
	{

	}

	void PlayerDebugController::OnFixedUpdate()
	{

	}
}