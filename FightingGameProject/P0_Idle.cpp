#include "P0_Idle.h"

namespace RB::Player0_States
{
	P0_Idle::P0_Idle()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
	}

	void P0_Idle::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();

		//temp

		if (_stateMachine->IsTransitioning())
		{
			return;
		}

		RB::Players::iPlayer* owner = GetOwnerPlayer();
		
		olc::HWButton jump = RB::Input::CurrentInputController::GetController()->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::JUMP);
		
		if (jump.bPressed || jump.bHeld)
		{
			_stateMachine->QueueNextState(new RB::Player0_States::JumpUp());
		
			return;
		}
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}