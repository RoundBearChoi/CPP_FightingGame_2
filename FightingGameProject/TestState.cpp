//#include "TestState.h"
//
//namespace RB::States
//{
//	TestState::~TestState()
//	{
//		std::cout << "destroying TestState" << std::endl;
//	}
//
//	void TestState::OnEnter()
//	{
//		std::cout << "entering TestState" << std::endl;
//	}
//	
//	void TestState::OnExit()
//	{
//		std::cout << "exiting TestState" << std::endl;
//	}
//	
//	void TestState::OnUpdate()
//	{
//		_stateMachine->QueueNextState(new TestState2());
//	}
//	
//	void TestState::OnFixedUpdate()
//	{
//		std::cout << "fixed update TestState" << std::endl;
//	}
//}