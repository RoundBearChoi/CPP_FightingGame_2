#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		//std::cout << "player id fixed update: " << player->GetPlayerIndex() << std::endl;
	}
}