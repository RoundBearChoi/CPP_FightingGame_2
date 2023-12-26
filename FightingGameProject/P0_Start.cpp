#include "P0_Start.h"
#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_Start::OnEnter()
	{
		// no sprite

		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(0, new RB::PlayerStates::Aku::P0_Idle()));

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

	void P0_Start::TransitionToIdle()
	{
		RB::States::iStateMachine* machine = GetPlayer()->GetStateMachine();

		machine->QueueNextState(new RB::PlayerStates::Aku::P0_Idle());
	}
}