#pragma once
#include <iostream>
#include "StateBase.h"
#include "SkipFixedUpdates.h"
#include "TriggerOnFixedUpdateCount.h"
#include "iPlayer.h"

namespace RB::P0_States
{
	class P0_Start : public RB::States::StateBase
	{
	public:
		P0_Start();
		~P0_Start() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void TransitionToIdle();

	private:
		Updaters::TriggerOnFixedUpdateCount<P0_Start> _triggerOnFixedUpdateCount;
		RB::Players::iPlayer* _ownerPlayer = nullptr;
	};
}