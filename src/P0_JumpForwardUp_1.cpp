#include "P0_JumpForwardUp_1.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpForwardUp_1::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_forward_1;

		AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 21.0f, new P0_Idle()));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump_1(20, 7.0f));

		EnterStateComponents();
	}

	void P0_JumpForwardUp_1::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpForwardUp_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpForwardUp_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
