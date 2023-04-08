#include "TestState.h"

namespace RB::States
{
	TestState::~TestState()
	{
		cout << "destroying TestState" << endl;
	}

	void TestState::OnEnter()
	{
		//cout << "entering TestState" << endl;
	}
	
	void TestState::OnExit()
	{
		//cout << "exiting TestState" << endl;
	}
	
	//void TestState::OnUpdate()
	//{
	//	//cout << Time::GetDeltaTime() << endl;
	//}
	
	//void TestState::OnFixedUpdate()
	//{
	//
	//}
}