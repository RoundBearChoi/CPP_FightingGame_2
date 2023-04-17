#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"
#include "P0_Idle.h"
#include "P0_MoveForward.h"
#include "WhileMovingBack.h"

namespace RB::Player0_States
{
	class P0_MoveBack : public RB::States::StateBase
	{
	public:
		P0_MoveBack();

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}