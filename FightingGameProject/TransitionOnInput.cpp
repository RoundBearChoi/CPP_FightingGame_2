#include "TransitionOnInput.h"

#include "iPlayerController.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	TransitionOnInput::TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input, bool useAsSpecial, bool useAsMovement)
	{
		_vecNextStates.push_back(nextState);
		_input = input;
		_useAsSpecial = useAsSpecial;
		_useAsMovement = useAsMovement;
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

		RB::Input::iInputObj* obj = nullptr;
		
		if (_useAsSpecial)
		{
			obj = RB::Input::iInputController::instance->GetUnused_Special_FIFO(playerID, _input);
		}
		else if (_useAsMovement)
		{
			obj = RB::Input::iInputController::instance->GetUnused_Movement_FIFO(playerID, _input);
		}
		
		if (obj == nullptr)
		{
			return;
		}

		if (_useAsSpecial && !obj->IsUsedAsSpecial())
		{
			obj->SetUsedAsSpecial(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}

		else if (_useAsMovement && !obj->IsUsedAsMovement())
		{
			obj->SetUsedAsMovement(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}
	}
}