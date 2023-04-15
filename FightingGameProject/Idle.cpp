#include "Idle.h"

namespace RB::PlayerStates
{
	Idle::Idle()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
	}

	void Idle::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void Idle::OnExit()
	{
		ExitStateComponents();
	}

	void Idle::OnUpdate()
	{
		UpdateStateComponents();

		if (_stateMachine->IsTransitioning())
		{
			return;
		}

		RB::Players::iPlayer* owner = GetOwnerPlayer();
		
		olc::HWButton jump = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::JUMP);
		//olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		//olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);
		
		if (jump.bPressed || jump.bHeld)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::JumpUp());
		
			return;
		}

		//if (moveLeft.bPressed && moveRight.bPressed)
		//{
		//	// do nothing
		//}
		//else if (moveLeft.bPressed)
		//{
		//	_stateMachine->QueueNextState(new RB::PlayerStates::MoveBack());
		//
		//	return;
		//}
		//else if (moveRight.bPressed)
		//{
		//	_stateMachine->QueueNextState(new RB::PlayerStates::MoveForward());
		//
		//	return;
		//}
		//
		////temp
		//if (moveLeft.bHeld && moveRight.bHeld)
		//{
		//	// do nothing
		//}
		//else if (moveLeft.bHeld)
		//{
		//	_stateMachine->QueueNextState(new RB::PlayerStates::MoveBack());
		//
		//	return;
		//}
		//else if (moveRight.bHeld)
		//{
		//	_stateMachine->QueueNextState(new RB::PlayerStates::MoveForward());
		//
		//	return;
		//}
	}

	void Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}