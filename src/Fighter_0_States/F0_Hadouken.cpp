#include "F0_Hadouken.h"

namespace RB::Fighter_0_States
{
	F0_Hadouken::F0_Hadouken()
	{
		_spriteType = Sprites::SpriteType::fighter_0_hadouken;
	}

	void F0_Hadouken::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::FixSpecialMoveStatusDuringState(true));
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_Hadouken::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Hadouken::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Hadouken::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
