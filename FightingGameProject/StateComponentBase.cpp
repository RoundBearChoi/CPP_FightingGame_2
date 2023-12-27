#include "StateComponentBase.h"

namespace RB::States
{
	/// <summary>
	/// delete nextState pointer if it's not used
	/// </summary>
	StateComponentBase::~StateComponentBase()
	{
		for (auto i = _vecNextStates.rbegin(); i != _vecNextStates.rend(); i++)
		{
			if ((*i) != nullptr)
			{
				RB::States::iState* state = (*i);

				if ((*i)->IsInQueue() == false)
				{
					delete (*i);
					(*i) = nullptr;
				}
			}
		}

		_vecNextStates.clear();
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

	void StateComponentBase::DeleteNextState(unsigned int creationID)
	{
		auto it = _vecNextStates.begin();

		while (it != _vecNextStates.end())
		{
			if ((*it)->GetCreationID() == creationID)
			{
				delete (*it);
				(*it) = nullptr;

				it = _vecNextStates.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	
	const int& StateComponentBase::GetFixedUpdateOnCount() const
	{
		return _fixedUpdateOnCount;
	}
}