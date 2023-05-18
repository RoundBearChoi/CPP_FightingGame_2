#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "TriggerJumpUp.h"
#include "WhileMovingBack.h"

namespace RB::P0_States
{
	class P0_MoveBack : public RB::States::StateBase
	{
	public:
		P0_MoveBack() = default;
		~P0_MoveBack() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}