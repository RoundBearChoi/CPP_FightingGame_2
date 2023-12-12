#include "P0_JumpUp_0.h"

namespace RB::PlayerStates
{
	void P0_JumpUp_0::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(15, 28.0f, new P0_FallDown()));

		EnterStateComponents();
	}

	void P0_JumpUp_0::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
