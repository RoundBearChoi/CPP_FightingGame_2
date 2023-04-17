#include "P0_Start.h"
#include "P0_Idle.h"

namespace RB::Player0_States
{
	P0_Start::P0_Start()
	{

	}

	void P0_Start::OnEnter()
	{
		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &P0_Start::TransitionToIdle);
	}

	void P0_Start::OnFixedUpdate()
	{
		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void P0_Start::TransitionToIdle()
	{
		_stateMachine->QueueNextState(new RB::Player0_States::P0_Idle());
	}
}