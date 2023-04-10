#include "PlayerTestState.h"

namespace RB::PlayerStates
{
	PlayerTestState::PlayerTestState()
	{

	}

	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnEnter()
	{
		_customUpdater.SetSkipFrames(5);
		_customUpdater.SetFunction(this, &PlayerTestState::Move);
	}

	void PlayerTestState::OnFixedUpdate()
	{
		_customUpdater.CallFunction();
	}

	void PlayerTestState::Move()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());
		
		player->Move(olc::vi2d{ 1, 1 });
	}
}