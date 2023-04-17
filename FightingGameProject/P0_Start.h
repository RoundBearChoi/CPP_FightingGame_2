#pragma once
#include <iostream>
#include "StateBase.h"
#include "GameplayControllers.h"
#include "iPlayer.h"
#include "SkipFixedUpdates.h"
#include "TriggerOnFixedUpdateCount.h"

namespace RB::Player0_States
{
	class P0_Start : public RB::States::StateBase
	{
	public:
		P0_Start();

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	public:
		void TransitionToIdle();

	private:
		Updaters::TriggerOnFixedUpdateCount<P0_Start> _triggerOnFixedUpdateCount;
	};
}