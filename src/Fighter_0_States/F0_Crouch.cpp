#include "F0_Crouch.h"

namespace RB::Fighter_0_States
{
	F0_Crouch::F0_Crouch()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_crouch;
	}
	
	void F0_Crouch::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Crouch_Idle()));

		EnterStateComponents();
	}

	void F0_Crouch::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Crouch::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Crouch::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
