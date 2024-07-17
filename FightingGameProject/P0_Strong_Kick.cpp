#include "P0_Strong_Kick.h"

namespace RB::PlayerStates::Aku
{
	void P0_Strong_Kick::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_strong_kick;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Strong_Kick::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Strong_Kick::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Strong_Kick::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
