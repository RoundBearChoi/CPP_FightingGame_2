#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"
#include "P0_Idle.h"
#include "P0_MoveBack.h"
#include "WhileMovingForward.h"

namespace RB::P0_States
{
	class P0_MoveForward : public RB::States::StateBase
	{
	public:
		P0_MoveForward();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}