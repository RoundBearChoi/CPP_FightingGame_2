#include "StateComponentBase.h"

namespace RB::States
{
	/// <summary>
	/// delete nextState pointer if it's not entered
	/// </summary>
	StateComponentBase::~StateComponentBase()
	{
		for (size_t i = 0; i < _vecNextStates.size(); i++)
		{
			if (_vecNextStates[i] != nullptr)
			{
				if (!_vecNextStates[i]->Entered())
				{
					delete _vecNextStates[i];
					_vecNextStates[i] = nullptr;
				}
			};
		};

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
	
	const int32_t& StateComponentBase::GetFixedUpdateOnCount() const
	{
		return _fixedUpdateOnCount;
	}

	const int32_t& StateComponentBase::GetUpdateOnCount() const
	{
		return _updateOnCount;
	}
}