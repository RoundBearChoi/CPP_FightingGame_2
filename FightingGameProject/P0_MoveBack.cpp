#include "P0_MoveBack.h"

namespace RB::PlayerStates
{
	void P0_MoveBack::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::NONE;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack(new RB::PlayerStates::P0_Idle(), new RB::PlayerStates::P0_MoveBack()));

		EnterStateComponents();
	}

	void P0_MoveBack::OnExit()
	{
		ExitStateComponents();
	}

	void P0_MoveBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_MoveBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}