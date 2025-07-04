#include "F0_StandUp.h"

namespace RB::Fighter_0_States
{
	F0_StandUp::F0_StandUp()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_standup;
	}

	void F0_StandUp::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new F0_Idle()));

		EnterStateComponents();
	}

	void F0_StandUp::OnExit()
	{
		ExitStateComponents();

	}

	void F0_StandUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_StandUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
