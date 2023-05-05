#include "P0_Idle.h"

namespace RB::P0_States
{
	P0_Idle::P0_Idle()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
	}

	void P0_Idle::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}