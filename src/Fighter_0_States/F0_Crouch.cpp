#include "F0_Crouch.h"

namespace RB::Fighter_0_States
{
	void F0_Crouch::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_crouch;

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