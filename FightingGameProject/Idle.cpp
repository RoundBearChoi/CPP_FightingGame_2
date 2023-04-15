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

		//temp

		if (_stateMachine->IsTransitioning())
		{
			return;
		}

		RB::Players::iPlayer* owner = GetOwnerPlayer();
		
		olc::HWButton jump = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::JUMP);
		
		if (jump.bPressed || jump.bHeld)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::JumpUp());
		
			return;
		}
	}

	void Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}