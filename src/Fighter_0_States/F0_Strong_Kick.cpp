#include "F0_Strong_Kick.h"

namespace RB::Fighter_0_States
{
	F0_Strong_Kick::F0_Strong_Kick()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_strong_kick;
	}
	void F0_Strong_Kick::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::DetectHit());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_Strong_Kick::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Strong_Kick::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Strong_Kick::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
