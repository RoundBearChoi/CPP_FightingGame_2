/*
#include "ManualTransitioner.h"

namespace RB::States
{
	ManualTransitioner::~ManualTransitioner()
	{
		//only delete at the end of program
		if (!_transitioning)
		{
			delete _prevState;
			delete _nextState;
		}
	}

	void ManualTransitioner::OnEnter(size_t stateMachineID, RB::States::iState* prev, RB::States::iState* next)
	{
		_stateMachineID = stateMachineID;
		_prevState = prev;
		_nextState = next;
	}

	void ManualTransitioner::OnUpdate()
	{
		_transitioning = _ToPrev();

		if (_transitioning)
		{
			return;
		}

		_transitioning = _ToNext();
	}

	void ManualTransitioner::OnFixedUpdate()
	{

	}
	
	bool ManualTransitioner::_ToPrev()
	{
		olc::HWButton home = olc::Platform::ptrPGE->GetKey(olc::Key::HOME);

		if (home.bPressed)
		{
			if (_prevState != nullptr)
			{
				RB::States::iStateMachine* m = RB::States::ActiveStateMachines::GetStateMachine(_stateMachineID);
				delete _nextState;
				_nextState = nullptr;
				m->QueueNextState(_prevState);

				return true;
			}
		}

		return false;
	}

	bool ManualTransitioner::_ToNext()
	{
		olc::HWButton end = olc::Platform::ptrPGE->GetKey(olc::Key::END);

		if (end.bPressed)
		{
			if ((_nextState != nullptr))
			{
				RB::States::iStateMachine* m = RB::States::ActiveStateMachines::GetStateMachine(_stateMachineID);
				delete _prevState;
				_prevState = nullptr;
				m->QueueNextState(_nextState);

				return true;
			}
		}

		return false;
	}
}
*/