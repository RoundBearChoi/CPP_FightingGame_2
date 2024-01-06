#include "P0_JumpForwardUp_1.h"

#include "MoveDownOnFall.h"
#include "MoveForwardOnJump_1.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpForwardUp_1::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteType::aku_jump_forward_up_1;

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