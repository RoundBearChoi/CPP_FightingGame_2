#include "TriggerJab.h"

namespace RB::PlayerStateComponents
{
	TriggerJab::TriggerJab(RB::States::iState* nextState)
	{
		//_nextState = nextState;
		_vecNextStates.push_back(nextState);
	}

	TriggerJab::~TriggerJab()
	{

	}

	void TriggerJab::OnEnter()
	{

	}

	void TriggerJab::OnExit()
	{

	}

	void TriggerJab::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Input::iInputController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		RB::Input::iInputObj* obj = RB::Input::iInputController::instance->GetUnusedInputObj_FIFO(playerID, RB::Input::PlayerInput::ATTACK_WEAK_PUNCH);

		if (obj != nullptr)
		{
			obj->SetUsedStatus(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			//machine->QueueNextState(_nextState);
			machine->QueueNextState(_vecNextStates[0]);

			return;
		}
	}
}