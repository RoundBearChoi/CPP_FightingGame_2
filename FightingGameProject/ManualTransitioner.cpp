#include "ManualTransitioner.h"

namespace RB::States
{
	void ManualTransitioner::OnEnter(size_t stateMachineID, RB::States::iState* prev, RB::States::iState* next)
	{
		_stateMachineID = stateMachineID;
		_prevState = prev;
		_nextState = next;
	}

	void ManualTransitioner::OnUpdate()
	{
		if (_ToPrev())
		{
			return;
		}

		_ToNext();
	}

	void ManualTransitioner::OnFixedUpdate()
	{

	}
	
	bool ManualTransitioner::_ToPrev()
	{
		olc::HWButton home = olc::Platform::ptrPGE->GetKey(olc::Key::HOME);

		if (home.bPressed)
		{
			RB::States::iStateMachine* m = RB::States::ActiveStateMachines::GetStateMachine(_stateMachineID);
			delete _nextState;
			m->QueueNextState(_prevState);

			return true;
		}

		return false;
	}

	bool ManualTransitioner::_ToNext()
	{
		olc::HWButton end = olc::Platform::ptrPGE->GetKey(olc::Key::END);

		if (end.bPressed)
		{
			RB::States::iStateMachine* m = RB::States::ActiveStateMachines::GetStateMachine(_stateMachineID);
			delete _prevState;
			m->QueueNextState(_nextState);

			return true;
		}
		return false;
	}
}