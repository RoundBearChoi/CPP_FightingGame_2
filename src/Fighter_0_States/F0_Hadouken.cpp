#include "F0_Hadouken.h"

namespace RB::Fighter_0_States
{
	void F0_Hadouken::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_hadouken;

		AddStateComponent(new RB::PlayerStateComponents::FixSpecialMoveStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::Fighter_0_States::P0_Idle()));

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
