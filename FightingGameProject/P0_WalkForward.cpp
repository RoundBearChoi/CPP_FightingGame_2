#include "P0_WalkForward.h"

namespace RB::PlayerStates
{
	void P0_WalkForward::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::PlayerStates::P0_JumpForwardUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward(new RB::PlayerStates::P0_Idle(), new RB::PlayerStates::P0_WalkBack()));

		EnterStateComponents();
	}

	void P0_WalkForward::OnExit()
	{
		ExitStateComponents();
	}

	void P0_WalkForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_WalkForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}