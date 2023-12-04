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
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		//_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);
	}

	void P0_Start::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void P0_Start::TransitionToIdle()
	{
		//if (_ownerPlayer == nullptr)
		//{
		//	return;
		//}

		RB::States::iStateMachine* machine = GetPlayer()->GetStateMachine();

		machine->QueueNextState(new RB::PlayerStates::P0_Idle());
	}
}