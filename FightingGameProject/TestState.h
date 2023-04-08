#pragma once
#include <iostream>
#include "StateBase.h"
#include "Time.h"
#include "TestState2.h"

using namespace std;
using namespace RB::Frames;

namespace RB::States
{
	class TestState : public StateBase
	{
	public:
		~TestState() override;

		virtual void OnEnter();
		virtual void OnExit();
		virtual void OnUpdate();
		virtual void OnFixedUpdate();
	};
}