#include "P0_MoveForward.h"

namespace RB::P0_States
{
	void P0_MoveForward::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
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