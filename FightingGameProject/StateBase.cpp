#include "StateBase.h"

namespace RB::States
{
	StateBase::~StateBase()
	{
		for (int i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}
	}

	void StateBase::SetStateMachine(iStateMachine* stateMachine)
	{
		_stateMachine = stateMachine;
	}

	iStateMachine* StateBase::GetStateMachine()
	{
		return _stateMachine;
	}
	
	void StateBase::QueueNextState(iState* nextState)
	{
		_stateMachine->QueueNextState(nextState);
	}

	void StateBase::AddCumulatedFixedUpdate()
	{
		_cumulatedFixedUpdates++;
	}

	unsigned int StateBase::GetCumulatedFixedUpdates()
	{
		return _cumulatedFixedUpdates;
	}

	RB::Players::iPlayer* StateBase::GetOwnerPlayer()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		return player;
	}

	RB::Sprites::SpriteID StateBase::GetSpriteID()
	{
		return _spriteID;
	}

	void StateBase::AddStateComponent(StateComponentBase* stateComponent)
	{
		stateComponent->SetState(this);

		_vecStateComponents.push_back(stateComponent);
	}

	void StateBase::EnterStateComponents()
	{
		for (int i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnEnter();
		}
	}

	void StateBase::ExitStateComponents()
	{
		for (int i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnExit();
		}
	}

	void StateBase::UpdateStateComponents()
	{
		for (int i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnUpdate();
		}
	}

	void StateBase::FixedUpdateStateComponents()
	{
		for (int i = 0; i < _vecStateComponents.size(); i++)
		{
			_vecStateComponents[i]->OnFixedUpdate();
		}
	}
}