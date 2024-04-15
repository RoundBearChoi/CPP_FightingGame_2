#include "StandUpOnRelease.h"

#include "iPlayerController.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	StandUpOnRelease::StandUpOnRelease(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void StandUpOnRelease::OnEnter()
	{

	}

	void StandUpOnRelease::OnFixedUpdate()
	{
		if (RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		bool down = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_DOWN);
		bool downLeft = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_DOWN_LEFT);
		bool downRight = RB::Input::iInputController::Get()->IsHeld(player->GetPlayerID(), RB::Input::PlayerInput::MOVE_DOWN_RIGHT);

		//do nothing if down is held (including diag)
		if (down || downLeft || downRight)
		{
			return;
		}
		
		//if down is released, go to next state
		player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
	}
}