#include "TestState.h"

namespace RB::States
{
	TestState::~TestState()
	{
		cout << "destroying TestState" << endl;
	}

	void TestState::OnEnter()
	{
		cout << "entering TestState" << endl;
	}
	
	void TestState::OnExit()
	{
		cout << "exiting TestState" << endl;
	}
	
	void TestState::OnUpdate()
	{
		_stateMachine->QueueNextState(new TestState2());
	}
	
	void TestState::OnFixedUpdate()
	{
		cout << "fixed update TestState" << endl;
	}
}