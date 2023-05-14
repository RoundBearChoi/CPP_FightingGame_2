#include "StateBase.h"

namespace RB::States
{
	StateBase::StateBase()
	{

	}

	StateBase::~StateBase()
	{
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}
	}

	//void StateBase::SetStateMachine(iStateMachine* stateMachine)
	//{
	//	_stateMachine = stateMachine;
	//}

	void StateBase::SetStateMachineID(size_t id)
	{
		_stateMachineID = id;
	}

	size_t StateBase::GetStateMachineID()
	{
		return _stateMachineID;
	}

	//iStateMachine* StateBase::GetStateMachine()
	//{
	//	return _stateMachine;
	//}
	
	//void StateBase::QueueNextState(iState* nextState)
	//{
	//	_stateMachine->QueueNextState(nextState);
	//}

	void StateBase::SetTransitionStatus(bool status)
	{
		_isTransitioning = status;
	}

	void StateBase::AddCumulatedFixedUpdate()
	{
		_cumulatedFixedUpdates++;
	}

	size_t StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	RB::Sprites::SpriteID StateBase::GetSpriteID()
	{
		return _spriteID;
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

			if (_isTransitioning) //(_stateMachine->IsTransitioning())
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

			if (_isTransitioning) //(_stateMachine->IsTransitioning())
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

			if (_isTransitioning)  //(_stateMachine->IsTransitioning())
			{
				break;
			}
		}
	}
}