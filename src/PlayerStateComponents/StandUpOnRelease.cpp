#include "StandUpOnRelease.h"

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
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (inputController == nullptr)
		{
			return;
		}

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		bool down = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_DOWN);
		bool downLeft = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_DOWN_LEFT);
		bool downRight = inputController->IsHeld(player->GetPLAYER_TYPE(), RB::Input::PlayerInput::MOVE_DOWN_RIGHT);

		//do nothing if down is held (including diag)
		if (down || downLeft || downRight)
		{
			return;
		}
		
		//if down is released, go to next state
		player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
	}
}
