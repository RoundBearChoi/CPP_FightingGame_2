#include "F0_Jab.h"

namespace RB::Fighter_0_States
{
	void F0_Jab::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_jab;

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