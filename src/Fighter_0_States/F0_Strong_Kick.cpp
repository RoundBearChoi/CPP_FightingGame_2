#include "F0_Strong_Kick.h"

namespace RB::Fighter_0_States
{
	void F0_Strong_Kick::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_strong_kick;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::Fighter_0_States::F0_Idle()));

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
