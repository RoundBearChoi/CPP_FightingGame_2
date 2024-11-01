#include "TransitionOnInput.h"

namespace RB::PlayerStateComponents
{
	TransitionOnInput::TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input, RB::Input::InputType inputType)
	{
		_vecNextStates.push_back(nextState);
		_input = input;
		_inputType = inputType;
	}

	void TransitionOnInput::OnEnter()
	{

	}

	void TransitionOnInput::OnExit()
	{

	}

	void TransitionOnInput::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		RB::Input::iInputObj* obj = nullptr;
		
		if (_inputType == RB::Input::InputType::ATTACK)
		{
			obj = RB::Input::iInputController::Get()->GetUnused_Special_FIFO(playerID, _input);
		}
		else if (_inputType == RB::Input::InputType::MOVEMENT)
		{
			obj = RB::Input::iInputController::Get()->GetUnused_Movement_FIFO(playerID, _input);
		}
		
		if (obj == nullptr)
		{
			return;
		}

		if (_inputType == RB::Input::InputType::ATTACK && !obj->IsUsedAsAttack())
		{
			obj->SetUsedAsAttack(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}

		else if (_inputType == RB::Input::InputType::MOVEMENT && !obj->IsUsedAsMovement())
		{
			obj->SetUsedAsMovement(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}
	}
}
