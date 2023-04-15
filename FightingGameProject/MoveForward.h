#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"
#include "Idle.h"
#include "MoveBack.h"
#include "WhileMovingForward.h"

namespace RB::PlayerStates
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