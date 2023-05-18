#include "P0_Start.h"
#include "P0_Idle.h"

namespace RB::PlayerStates
{
	void P0_Start::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		// no sprite

		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &P0_Start::TransitionToIdle);
	}

	void P0_Start::OnExit()
	{
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Start::OnUpdate()
	{
		_getter_PlayerController.OnUpdate();

		if (_getter_PlayerController.GetController() == nullptr)
		{
			return;
		}

		_ownerPlayer = _getter_PlayerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);
	}

	void P0_Start::OnFixedUpdate()
	{
		if (_getter_PlayerController.GetController() == nullptr || _ownerPlayer == nullptr)
		{
			return;
		}

		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void P0_Start::TransitionToIdle()
	{
		RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();

		machine->QueueNextState(new RB::PlayerStates::P0_Idle());
	}
}