#include "MoveForward.h"

namespace RB::Player0_States
{
	MoveForward::MoveForward()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_walk;
	}

	void MoveForward::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward());

		EnterStateComponents();
	}

	void MoveForward::OnExit()
	{
		ExitStateComponents();
	}

	void MoveForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void MoveForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}