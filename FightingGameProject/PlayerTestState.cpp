#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::PlayerTestState()
	{
		//void (PlayerTestState::*dfdfdfdf)() = &PlayerTestState::SomeFunc;

		//_updater = new Updaters::SkipFrameUpdater(1, &PlayerTestState::SomeFunc);
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
}