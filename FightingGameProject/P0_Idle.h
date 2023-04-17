#pragma once
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "CurrentInputController.h"
#include "P0_JumpUp.h"
#include "MoveForward.h"
#include "P0_MoveBack.h"
#include "TriggerMoveForward.h"
#include "TriggerMoveBack.h"

namespace RB::Player0_States
{
	class P0_Idle : public RB::States::StateBase
	{
	public:
		P0_Idle();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}