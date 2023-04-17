#include "Idle.h"

namespace RB::Player0_States
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
		
		olc::HWButton jump = RB::Input::CurrentInputController::GetController()->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::JUMP);
		
		if (jump.bPressed || jump.bHeld)
		{
			_stateMachine->QueueNextState(new RB::Player0_States::JumpUp());
		
			return;
		}
	}

	void Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}