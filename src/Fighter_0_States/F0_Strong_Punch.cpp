#include "F0_Strong_Punch.h"

namespace RB::Fighter_0_States
{
	F0_Strong_Punch::F0_Strong_Punch()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_strong_punch;
	}

	void F0_Strong_Punch::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::DetectHit());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_Strong_Punch::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Strong_Punch::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Strong_Punch::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
