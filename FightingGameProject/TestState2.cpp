#include "TestState2.h"

namespace RB::States
{
	TestState2::~TestState2()
	{
		cout << "destroying TestState2" << endl;
	}

	void TestState2::OnEnter()
	{
		cout << "entering TestState2" << endl;
	}

	void TestState2::OnExit()
	{
		cout << "exiting TestState2" << endl;
	}
}