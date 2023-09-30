#include "StateComponentBase.h"

namespace RB::States
{
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