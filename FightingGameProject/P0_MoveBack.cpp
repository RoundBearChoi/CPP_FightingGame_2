#include "P0_MoveBack.h"

namespace RB::P0_States
{
	P0_MoveBack::P0_MoveBack()
	{
		// no sprite yet
	}

	void P0_MoveBack::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack());

		EnterStateComponents();
	}

	void P0_MoveBack::OnExit()
	{
		ExitStateComponents();
	}

	void P0_MoveBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_MoveBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}