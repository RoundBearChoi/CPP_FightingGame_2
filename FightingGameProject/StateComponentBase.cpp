#include "StateComponentBase.h"

namespace RB::States
{
	/// <summary>
	/// delete nextState pointer if it's not entered
	/// </summary>
	StateComponentBase::~StateComponentBase()
	{
		if (_nextState != nullptr)
		{
			if (!_nextState->Entered())
			{
				delete _nextState;
				_nextState = nullptr;
			}
		}
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
	
	const int32_t& StateComponentBase::GetFixedUpdateOnCount() const
	{
		return _fixedUpdateOnCount;
	}

	const int32_t& StateComponentBase::GetUpdateOnCount() const
	{
		return _updateOnCount;
	}
}