#include "StateComponentBase.h"

namespace RB::States
{
	/// <summary>
	/// delete nextState pointer if it's not used
	/// </summary>
	StateComponentBase::~StateComponentBase()
	{
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
			if ((*i)->GetStateID() == stateID)
			{
				return true;
			}
		}

		return false;
	}
}