#include "P0_StandUp.h"

namespace RB::Fighter_0_States
{
	void P0_StandUp::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_standup;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new F0_Idle()));

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
