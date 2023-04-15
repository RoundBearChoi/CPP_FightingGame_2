#include "MoveForward.h"

namespace RB::PlayerStates
{
	MoveForward::MoveForward()
	{

	}

	void MoveForward::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::KeepMovingForward());

		EnterStateComponents();
	}

	void MoveForward::OnExit()
	{
		ExitStateComponents();
	}

	void MoveForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void MoveForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();

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
			_stateMachine->QueueNextState(new RB::PlayerStates::MoveBack());
		}
		else if (moveRight.bHeld)
		{
			RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

			player->Move(olc::vi2d{ 2, 0 });
		}
	}
}