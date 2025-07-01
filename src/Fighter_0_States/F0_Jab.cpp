#include "F0_Jab.h"

namespace RB::Fighter_0_States
{
	F0_Jab::F0_Jab()
	{
		_spriteType = Sprites::SpriteType::fighter_0_jab;
	}

	void F0_Jab::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::DetectHit());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_Jab::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Jab::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Jab::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
