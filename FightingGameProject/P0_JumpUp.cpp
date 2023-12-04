#include "P0_JumpUp.h"

namespace RB::PlayerStates
{
	void P0_JumpUp::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(15, 28.0f, new P0_FallDown()));

		EnterStateComponents();
	}

	void P0_JumpUp::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}