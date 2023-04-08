#pragma once
#include <iostream>
#include "StateBase.h"

using namespace std;

namespace RB::States
{
	class TestState2 : public StateBase
	{
	public:
		~TestState2() override;

		void OnEnter() override;
		void OnExit() override;
	};
}