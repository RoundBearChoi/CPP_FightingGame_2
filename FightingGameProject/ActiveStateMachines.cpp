#include "ActiveStateMachines.h"

namespace RB::States
{
	void ActiveStateMachines::Init()
	{

	}

	void ActiveStateMachines::OnEnd()
	{
		//pointers should already be deleted by owners
		_vecStateMachines.clear();

		ResetID();
	}

	void ActiveStateMachines::AddStateMachine(iStateMachine* stateMachine)
	{
		if (stateMachine != nullptr)
		{
			_vecStateMachines.push_back(stateMachine);
		}
	}

	void ActiveStateMachines::ResetID()
	{
		_cumulatedID = 0;
	}

	int ActiveStateMachines::GetID()
	{
		_cumulatedID++;

		return _cumulatedID;
	}
}