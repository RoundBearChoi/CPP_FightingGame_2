#include "P0_Start.h"

namespace RB::Fighter_0_States
{
	void P0_Start::OnEnter()
	{
		// no sprite

		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(0, new RB::Fighter_0_States::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Start::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Start::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Start::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
