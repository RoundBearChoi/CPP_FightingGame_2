#include "StateBase.h"

namespace RB::States
{
	StateBase::~StateBase()
	{
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecStateComponents.clear();
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
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnExit();
		}
	}

	void StateBase::UpdateStateComponents()
	{
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnUpdate();

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
			int32_t fixedUpdateOnCount = (*i)->GetFixedUpdateOnCount();

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