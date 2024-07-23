#include "P0_Strong_Punch.h"

namespace RB::Fighter_0_States
{
	void P0_Strong_Punch::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_strong_punch;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::Fighter_0_States::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Strong_Punch::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Strong_Punch::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Strong_Punch::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
