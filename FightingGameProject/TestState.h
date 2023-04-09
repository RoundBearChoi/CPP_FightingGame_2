#pragma once
#include <iostream>
#include "StateBase.h"
#include "Time.h"
#include "TestState2.h"

namespace RB::States
{
	class TestState : public StateBase
	{
	public:
		~TestState() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;
	};
}