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
		_skipFrame.SetSkipFrames(5);
		_skipFrame.SetFunction(this, &PlayerTestState::Move);
	}

	void PlayerTestState::OnFixedUpdate()
	{
		_skipFrame.CallFunction();
	}

	void PlayerTestState::Move()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());
		
		player->Move(olc::vi2d{ 1, 1 });
	}
}