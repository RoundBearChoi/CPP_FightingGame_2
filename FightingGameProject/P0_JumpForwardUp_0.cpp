#include "P0_JumpForwardUp_0.h"

namespace RB::PlayerStates
{
	void P0_JumpForwardUp_0::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0);

		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(16, 25.0f, new P0_JumpForwardUp_1));

		EnterStateComponents();
	}

	void P0_JumpForwardUp_0::OnExit()
	{
		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_JumpForwardUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpForwardUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}