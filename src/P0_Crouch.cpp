#include "P0_Crouch.h"

namespace RB::Fighter_0_States
{
	void P0_Crouch::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_crouch;

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnAnimationEnd(new RB::Fighter_0_States::P0_Crouch_Idle()));

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
