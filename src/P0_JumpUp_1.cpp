#include "P0_JumpUp_1.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpUp_1::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_fall;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 20.0f, new P0_Idle()));

		EnterStateComponents();
	}

	void P0_JumpUp_1::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpUp_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
