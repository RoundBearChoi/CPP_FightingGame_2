#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"
#include "P0_Idle.h"
#include "P0_MoveBack.h"
#include "WhileMovingForward.h"

namespace RB::Player0_States
{
	class MoveForward : public RB::States::StateBase
	{
	public:
		MoveForward();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}