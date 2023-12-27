#include "StateBase.h"

namespace RB::States
{
	unsigned int StateBase::stateCreationCount = 0;

	/// <summary>
	/// ever state has unique creationID
	/// </summary>
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

	unsigned int StateBase::GetCreationID()
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

	void StateBase::SetIsTransitioning(bool status)
	{
		_isTransitioning = status;
	}

	void StateBase::SetIsInQueue(bool status)
	{
		_isInQueue = status;
	}

	bool StateBase::IsTransitioning()
	{
		return _isTransitioning;
	}

	bool StateBase::IsInQueue()
	{
		return _isInQueue;
	}

	void StateBase::AddCumulatedFixedUpdate()
	{
		_cumulatedFixedUpdates++;
	}

	unsigned int StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	void StateBase::DeleteNextState(unsigned int creationID)
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			(*i)->DeleteNextState(creationID);
		}
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