#include "P0_Strong_Punch.h"

#include "MarkInitiallyFacingRight.h"
#include "DetectHit.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_Strong_Punch::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::aku_strong_punch;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::Aku::P0_Idle()));

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