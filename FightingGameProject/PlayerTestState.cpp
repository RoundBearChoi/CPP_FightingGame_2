#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::PlayerTestState()
	{
		Updaters::SkipFrameUpdater<PlayerTestState>* sssss = new Updaters::SkipFrameUpdater<PlayerTestState>();
		sssss->Func = &PlayerTestState::SomeFunc;

		sssss->callMemberFunction();

		delete sssss;
	}

	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		player->Move(olc::vi2d{ 1, 1 });
	}

	void PlayerTestState::SomeFunc()
	{
		std::cout << "calling some delegated func..." << std::endl;
	}
}