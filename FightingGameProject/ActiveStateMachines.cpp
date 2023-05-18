#include "ActiveStateMachines.h"

namespace RB::States
{
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

	iStateMachine* ActiveStateMachines::GetStateMachine(size_t id)
	{
		for (size_t i = 0; i < _vecStateMachines.size(); i++)
		{
			if (_vecStateMachines[i]->GetID() == id)
			{
				return _vecStateMachines[i];
			}
		}

		return nullptr;
	}

	void ActiveStateMachines::ResetID()
	{
		_cumulatedID = 0;
	}

	size_t ActiveStateMachines::GetID()
	{
		_cumulatedID++;

		return _cumulatedID;
	}
}