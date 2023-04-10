#include "MoveForward.h"

namespace RB::PlayerStates
{
	MoveForward::MoveForward()
	{

	}

	MoveForward::~MoveForward()
	{

	}

	void MoveForward::OnEnter()
	{

	}

	void MoveForward::OnUpdate()
	{

	}

	void MoveForward::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();

		olc::HWButton button = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (button.bHeld)
		{
			RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

			player->Move(olc::vi2d{ 1, 0 });
		}
	}
}