#include "F0_StandUp.h"

namespace RB::Fighter_0_States
{
	void F0_StandUp::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_standup;

		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new F0_Idle()));

		EnterStateComponents();
	}

	void F0_StandUp::OnExit()
	{
		ExitStateComponents();

	}

	void F0_StandUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_StandUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}