#include "P0_MoveBack.h"

namespace RB::PlayerStates
{
	void P0_MoveBack::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		// no sprite yet

		_getter_PlayerController.FindController();
		_ownerPlayer = _getter_PlayerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack());

		EnterStateComponents();
	}

	void P0_MoveBack::OnExit()
	{
		ExitStateComponents();

		ActivePlayerStates::RemovePlayerState(this);
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