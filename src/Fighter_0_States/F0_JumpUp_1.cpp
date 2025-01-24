#include "F0_JumpUp_1.h"
#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	void F0_JumpUp_1::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_fall;

		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::MoveDownOnFall(20, 20.0f));
		AddStateComponent(new PlayerStateComponents::TransitionOnGround(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_JumpUp_1::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpUp_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpUp_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}