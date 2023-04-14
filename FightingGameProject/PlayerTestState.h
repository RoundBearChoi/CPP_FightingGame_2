#pragma once
#include <iostream>
#include "StateBase.h"
#include "GameplayControllers.h"
#include "iPlayer.h"
#include "SkipFixedUpdates.h"
#include "TriggerOnFixedUpdateCount.h"

namespace RB::PlayerStates
{
	class PlayerTestState : public RB::States::StateBase
	{
	public:
		PlayerTestState();

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	public:
		void Move();
		void TransitionToIdle();

	private:
		Updaters::TriggerOnFixedUpdateCount<PlayerTestState> _triggerOnFixedUpdateCount;
	};
}