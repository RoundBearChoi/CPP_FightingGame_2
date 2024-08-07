#include "F0_Strong_Punch.h"

namespace RB::Fighter_0_States
{
	void F0_Strong_Punch::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_strong_punch;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::Fighter_0_States::F0_Idle()));

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
