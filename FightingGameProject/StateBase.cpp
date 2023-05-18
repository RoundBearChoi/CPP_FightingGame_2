#include "StateBase.h"

namespace RB::States
{
	StateBase::~StateBase()
	{
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}
	}

	void StateBase::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	size_t StateBase::GetStateMachineID()
	{
		return _stateMachineID;
	}

	void StateBase::SetTransitionStatus(bool status)
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

	size_t StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	void StateBase::AddStateComponent(StateComponentBase* stateComponent)
	{
		if (stateComponent == nullptr)
		{
			std::cout << "wtf" << std::endl;
		}

		stateComponent->SetState(this);

		_vecStateComponents.push_back(stateComponent);
	}

	void StateBase::EnterStateComponents()
	{
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnEnter();

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
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnFixedUpdate();

			if (_isTransitioning)
			{
				break;
			}
		}
	}
}