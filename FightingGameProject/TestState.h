#pragma once
#include <iostream>
#include "StateBase.h"

using namespace std;

namespace RB::StateMachine
{
	class TestState : public StateBase
	{
	public:
		~TestState() override;

		//virtual void OnEnter();
		//virtual void OnExit();
		//virtual void OnUpdate();
		//virtual void OnFixedUpdate();
	};
}