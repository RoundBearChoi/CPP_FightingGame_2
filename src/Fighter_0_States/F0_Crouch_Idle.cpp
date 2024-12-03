#include "F0_Crouch_Idle.h"
#include "F0_Crouch_Punch_Weak.h"

namespace RB::Fighter_0_States
{
	void F0_Crouch_Idle::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_crouch_idle;

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new F0_Crouch_Punch_Weak(), RB::Input::PlayerInput::ATTACK_WEAK_PUNCH, RB::Input::InputType::ATTACK));
		AddStateComponent(new RB::PlayerStateComponents::StandUpOnRelease(new RB::Fighter_0_States::F0_StandUp()));

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