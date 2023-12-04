#pragma once
#include <iostream>
#include "PlayerState.h"
#include "iPlayer.h"

#include "SkipFixedUpdates.h"
#include "TriggerOnFixedUpdateCount.h"

namespace RB::PlayerStates
{
	class P0_Start : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Start() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void TransitionToIdle();

	private:
		Updaters::TriggerOnFixedUpdateCount<P0_Start> _triggerOnFixedUpdateCount;
	};
}