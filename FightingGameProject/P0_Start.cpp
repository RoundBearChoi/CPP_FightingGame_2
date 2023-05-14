#include "P0_Start.h"
#include "P0_Idle.h"

namespace RB::P0_States
{
	P0_Start::P0_Start()
	{
		// no sprite
	}

	void P0_Start::OnEnter()
	{
		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &P0_Start::TransitionToIdle);
	}

	void P0_Start::OnUpdate()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();

		if (pc != nullptr)
		{
			_ownerPlayer = pc->GetPlayerOnStateMachineID(_stateMachineID);
		}
	}

	void P0_Start::OnFixedUpdate()
	{
		if (_ownerPlayer != nullptr)
		{
			_triggerOnFixedUpdateCount.OnFixedUpdate();
		}
	}

	void P0_Start::TransitionToIdle()
	{
		RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

		machine->QueueNextState(new RB::P0_States::P0_Idle());
	}
}