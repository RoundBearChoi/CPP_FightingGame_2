#include "StateBase.h"

namespace RB::States
{
	unsigned int StateBase::stateCreationCount = 0;

	// ever state has stateID
	StateBase::StateBase()
	{
		stateCreationCount++;
		_stateCreationID = stateCreationCount;
	}

	StateBase::~StateBase()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecStateComponents.clear();
	}

	unsigned int StateBase::GetStateID()
	{
		return _stateCreationID;
	}

	void StateBase::SetStateMachineID(unsigned int id)
	{
		_stateMachineID = id;
	}

	unsigned int StateBase::GetStateMachineID()
	{
		return _stateMachineID;
	}

	void StateBase::SetStateMachineIDs_Recursively()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			(*i)->SetStateMachineID(_stateMachineID);
		}
	}

	void StateBase::SetIsTransitioning(bool status)
	{
		_isTransitioning = status;
	}

	bool StateBase::IsTransitioning()
	{
		return _isTransitioning;
	}

	void StateBase::AddCumulatedFixedUpdate()
	{
		_cumulatedFixedUpdates++;
	}

	unsigned int StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	bool StateBase::ContainsState_Recursive(unsigned int stateID)
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			if ((*i)->ContainsState(stateID))
			{
				return true;
			}
		}

		return false;
	}

	void StateBase::LogStateEnter()
	{
		std::cout << "entering state" << std::endl;
	}

	void StateBase::AddStateComponent(StateComponentBase* stateComponent)
	{
		if (stateComponent == nullptr)
		{
			std::cout << "null StateComponent" << std::endl;
		}

		stateComponent->SetState(this);

		_vecStateComponents.push_back(stateComponent);
	}

	void StateBase::EnterStateComponents()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			(*i)->OnEnter();

			if (_isTransitioning)
			{
				break;
			}
		}
	}

	void StateBase::ExitStateComponents()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			(*i)->OnExit();
		}
	}

	void StateBase::UpdateStateComponents()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			(*i)->OnUpdate();

			if (_isTransitioning)
			{
				break;
			}
		}
	}

	void StateBase::FixedUpdateStateComponents()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			int fixedUpdateOnCount = (*i)->GetFixedUpdateOnCount();

			if (fixedUpdateOnCount >= 0)
			{
				if (_cumulatedFixedUpdates != fixedUpdateOnCount)
				{
					continue;
				}
			}

			(*i)->OnFixedUpdate();

			if (_isTransitioning)
			{
				break;
			}
		}
	}
}
