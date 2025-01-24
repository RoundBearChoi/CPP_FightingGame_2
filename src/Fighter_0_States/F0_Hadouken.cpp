#include "F0_Hadouken.h"

namespace RB::Fighter_0_States
{
	void F0_Hadouken::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_hadouken;

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