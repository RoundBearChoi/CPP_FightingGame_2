#pragma once
#include "StateBase.h"
#include "ManualAnimationUpdater.h"
#include "ManualTransitioner.h"

#include "P0_Idle_Dummy.h"

namespace RB::P0_States
{
	class P0_FallDown_Dummy : public RB::States::StateBase
	{
	public:
		P0_FallDown_Dummy();
		~P0_FallDown_Dummy() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;
		RB::States::ManualTransitioner _manualTransitioner;
	};
}