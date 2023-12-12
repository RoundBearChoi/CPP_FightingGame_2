#include "P0_Idle.h"

namespace RB::PlayerStates
{
	void P0_Idle::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpForward());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::P0_JumpUp()));
		AddStateComponent(new RB::PlayerStateComponents::TriggerJab(new P0_Jab()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkForward(new RB::PlayerStates::P0_MoveForward()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkBack(new RB::PlayerStates::P0_MoveBack()));

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}