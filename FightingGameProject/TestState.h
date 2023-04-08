#pragma once
#include <iostream>
#include "StateBase.h"
#include "iState.h"

using namespace std;

namespace RB::StateMachine
{
	class TestState : StateBase, iState
	{
	public:
		~TestState() override;
	};
}