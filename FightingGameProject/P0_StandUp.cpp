#include "P0_StandUp.h"

#include "ToggleInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_StandUp::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_standup;

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new P0_Idle()));

		EnterStateComponents();
	}

	void P0_StandUp::OnExit()
	{
		ExitStateComponents();

	}

	void P0_StandUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_StandUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}