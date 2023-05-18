#pragma once
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "TriggerJumpUp.h"
#include "TriggerMoveForward.h"
#include "TriggerMoveBack.h"

namespace RB::P0_States
{
	class P0_Idle : public RB::States::StateBase
	{
	public:
		P0_Idle() = default;
		~P0_Idle() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}