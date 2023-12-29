#include "StateComponentBase.h"

namespace RB::States
{
	StateComponentBase::~StateComponentBase()
	{
		//next states are deleted by state machine
		//ie. PlayerState::ErasePreviousStates()

		//for (auto i = _vecNextStates.rbegin(); i != _vecNextStates.rend(); i++)
		//{
		//	delete (*i);
		//	(*i) = nullptr;
		//}
		//
		//_vecNextStates.clear();
	}

	void StateComponentBase::SetState(iState* state)
	{
		_state = state;
	}

	void StateComponentBase::OnEnter()
	{

	}

	void StateComponentBase::OnExit()
	{

	}

	void StateComponentBase::OnUpdate()
	{

	}

	void StateComponentBase::OnFixedUpdate()
	{

	}
	
	const int& StateComponentBase::GetFixedUpdateOnCount() const
	{
		return _fixedUpdateOnCount;
	}

	bool StateComponentBase::ContainsState(unsigned int stateID)
	{
		for (auto i = _vecNextStates.begin(); i != _vecNextStates.end(); i++)
		{
			if ((*i)->ContainsState_Recursive(stateID))
			{
				return true;
			}

			if ((*i)->GetStateID() == stateID)
			{
				return true;
			}
		}

		return false;
	}
	void StateComponentBase::SetStateMachineID(unsigned int id)
	{
		for (auto i = _vecNextStates.begin(); i != _vecNextStates.end(); i++)
		{
			(*i)->SetStateMachineID(id);
			(*i)->SetStateMachineIDs_Recursively();
		}
	}
}