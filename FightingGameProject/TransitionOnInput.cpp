#include "TransitionOnInput.h"

namespace RB::PlayerStateComponents
{
	TransitionOnInput::TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input)
	{
		_vecNextStates.push_back(nextState);
		_input = input;
	}

	TransitionOnInput::~TransitionOnInput()
	{

	}

	void TransitionOnInput::OnEnter()
	{

	}

	void TransitionOnInput::OnExit()
	{

	}

	void TransitionOnInput::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		RB::Input::iInputObj* obj = RB::Input::iInputController::instance->GetUnusedInputObj_FIFO(playerID, _input);

		if (obj != nullptr)
		{
			obj->SetUsedStatus(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);

			return;
		}
	}
}