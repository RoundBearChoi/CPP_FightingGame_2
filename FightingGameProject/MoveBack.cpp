#include "MoveBack.h"

namespace RB::PlayerStates
{
	MoveBack::MoveBack()
	{

	}

	MoveBack::~MoveBack()
	{

	}

	void MoveBack::OnEnter()
	{

	}

	void MoveBack::OnUpdate()
	{

	}

	void MoveBack::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (!moveLeft.bHeld && !moveRight.bHeld)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::Idle());

			return;
		}
		else if (moveLeft.bHeld && moveRight.bHeld)
		{
			// do nothing
		}
		else if (moveLeft.bHeld)
		{
			RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

			player->Move(olc::vi2d{ -1, 0 });
		}
		else if (moveRight.bHeld)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::MoveForward());
		}
	}
}