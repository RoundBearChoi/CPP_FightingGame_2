#include "TriggerJab.h"

namespace RB::PlayerStateComponents
{
	TriggerJab::TriggerJab(RB::States::iState* nextState)
	{
		_nextState = nextState;
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
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerID playerID = player->GetPlayerID();

		RB::Input::iInputObj* obj = RB::Input::INPUT_CONTROLLER->GetUnusedInputObj_FIFO(playerID, RB::Input::PlayerInput::ATTACK_WEAK_PUNCH);

		if (obj != nullptr)
		{
			obj->SetUsedStatus(true);

			RB::States::iStateMachine* machine = player->GetStateMachine();
			machine->QueueNextState(_nextState);

			return;
		}
	}
}