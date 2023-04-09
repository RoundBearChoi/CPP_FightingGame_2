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
		Updaters::SkipFrameUpdater<PlayerTestState>* testtest = new Updaters::SkipFrameUpdater<PlayerTestState>();
		testtest->SetTargetObj(this);
		testtest->SetMemberFunction(&PlayerTestState::SomeFunc);
		testtest->callMemberFunction();

		delete testtest;
	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		player->Move(olc::vi2d{ 1, 1 });
	}

	void PlayerTestState::SomeFunc()
	{
		std::cout << "calling some delegated func..." << std::endl;
		std::cout << "statemachine id: " << _stateMachine->GetID() << std::endl;
	}
}