#include "P0_MoveForward.h"

namespace RB::PlayerStates
{
	void P0_MoveForward::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::P0_JumpUp()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward());

		EnterStateComponents();
	}

	void P0_MoveForward::OnExit()
	{
		ExitStateComponents();
	}

	void P0_MoveForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_MoveForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}