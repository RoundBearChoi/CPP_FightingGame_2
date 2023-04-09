#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::PlayerTestState()
	{
		//_updater = new RB::Updaters::SkipFrameUpdater(1, &SomeFunc);
	}

	PlayerTestState::~PlayerTestState()
	{
		delete _updater;
	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		player->Move(olc::vi2d{ 1, 1 });
	}

	void PlayerTestState::SomeFunc()
	{
	
	}
}