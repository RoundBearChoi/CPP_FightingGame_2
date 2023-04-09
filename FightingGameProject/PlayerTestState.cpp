#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		player->Move(olc::vi2d{ 1, 1 });
	}

	//void PlayerTestState::_SomeFunc()
	//{
	//
	//}
}