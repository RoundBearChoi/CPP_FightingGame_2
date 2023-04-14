#pragma once
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "JumpUp.h"
#include "MoveForward.h"
#include "MoveBack.h"
//#include "TestComponent.h"
#include "TriggerMoveForward.h"

namespace RB::PlayerStates
{
	class Idle : public RB::States::StateBase
	{
	public:
		Idle();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}