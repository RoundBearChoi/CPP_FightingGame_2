#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::PlayerTestState()
	{

	}

	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnEnter()
	{
		_customUpdater.SetSkipFrames(1);
		_customUpdater.SetTargetObj(this);
		_customUpdater.SetTargetFunction(&PlayerTestState::SomeFunc);
	}

	void PlayerTestState::OnFixedUpdate()
	{
		_customUpdater.CallTargetFunction();
	}

	void PlayerTestState::SomeFunc()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());
		
		player->Move(olc::vi2d{ 1, 1 });
	}
}