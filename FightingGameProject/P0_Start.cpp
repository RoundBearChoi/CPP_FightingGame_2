#include "P0_Start.h"
#include "P0_Idle.h"

namespace RB::PlayerStates
{
	void P0_Start::OnEnter()
	{
		// no sprite

		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &P0_Start::TransitionToIdle);
	}

	void P0_Start::OnExit()
	{

	}

	void P0_Start::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}
	}

	void P0_Start::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void P0_Start::TransitionToIdle()
	{
		RB::States::iStateMachine* machine = GetPlayer()->GetStateMachine();

		machine->QueueNextState(new RB::PlayerStates::P0_Idle());
	}
}