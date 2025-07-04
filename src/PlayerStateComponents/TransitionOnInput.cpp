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
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr || inputController == nullptr)
		{
			return;
		}

		Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		Players::PLAYER_TYPE playerID = player->GetPLAYER_TYPE();

		RB::Input::iInputObj* obj = nullptr;
		
		if (_inputType._value == RB::Input::InputType::ATTACK)
		{
			obj = inputController->GetUnused_Special_FIFO(playerID, _input);
		}
		else if (_inputType._value == RB::Input::InputType::MOVEMENT)
		{
			obj = inputController->GetUnused_Movement_FIFO(playerID, _input);
		}
		
		if (obj == nullptr)
		{
			return;
		}

		if (_inputType._value == RB::Input::InputType::ATTACK && !obj->IsUsedAsAttack())
		{
			obj->SetUsedAsAttack(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}

		else if (_inputType._value == RB::Input::InputType::MOVEMENT && !obj->IsUsedAsMovement())
		{
			obj->SetUsedAsMovement(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_vecNextStates[0]);
		}
	}
}
