#include "P0_MoveForward.h"

namespace RB::P0_States
{
	P0_MoveForward::P0_MoveForward()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_walk;
	}

	void P0_MoveForward::OnEnter()
	{
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