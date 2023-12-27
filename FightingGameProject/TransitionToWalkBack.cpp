#include "TransitionToWalkBack.h"

namespace RB::PlayerStateComponents
{
	TransitionToWalkBack::TransitionToWalkBack(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);

		std::cout << "added state to vecNextStates - stateID " << nextState->GetCreationID() << std::endl;
	}

	TransitionToWalkBack::~TransitionToWalkBack()
	{
		for (auto i = _vecNextStates.begin(); i != _vecNextStates.end(); i++)
		{
			std::cout << "attempting to delete vecNextStates - stateID " << (*i)->GetCreationID() << std::endl;
		}
	}

	void TransitionToWalkBack::OnEnter()
	{
		_moveBackOnPress.SetStateMachineID(_state->GetStateMachineID());
	}

	void TransitionToWalkBack::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		if (player == nullptr)
		{
			return;
		}

		_moveBackOnPress.OnUpdate();

		if (_moveBackOnPress.ProcMoveBack())
		{
			RB::States::iStateMachine* stateMachine = player->GetStateMachine();

			stateMachine->QueueNextState(_vecNextStates[0]);
		}
	}
}