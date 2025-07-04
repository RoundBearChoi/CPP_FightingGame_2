#include "F0_Crouch_Idle.h"
#include "F0_Crouch_Punch_Weak.h"

namespace RB::Fighter_0_States
{
	F0_Crouch_Idle::F0_Crouch_Idle()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_crouch_idle;
	}
	
	void F0_Crouch_Idle::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new PlayerStateComponents::TransitionOnInput(new F0_Crouch_Punch_Weak(), Input::PlayerInput::ATTACK_WEAK_PUNCH, Input::InputType::ATTACK));
		AddStateComponent(new PlayerStateComponents::StandUpOnRelease(new Fighter_0_States::F0_StandUp()));
		AddStateComponent(new PlayerStateComponents::MarkCrouchingOnEnter(true));
		AddStateComponent(new PlayerStateComponents::MarkCrouchingOnExit(false));

		EnterStateComponents();
	}

	void F0_Crouch_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Crouch_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Crouch_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
