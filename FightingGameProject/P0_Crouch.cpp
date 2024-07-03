#include "P0_Crouch.h"

#include "MarkInitiallyFacingRight.h"
#include "TransitionOnAnimationEnd.h"

#include "P0_Crouch_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_Crouch::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_crouch;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::PlayerStates::Aku::P0_Crouch_Idle()));

		EnterStateComponents();
	}

	void P0_Crouch::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Crouch::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Crouch::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}