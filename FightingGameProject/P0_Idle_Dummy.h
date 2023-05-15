#pragma once
#include "StateBase.h"
#include "ManualAnimationUpdater.h"
#include "ManualTransitioner.h"

namespace RB::P0_States
{
	class P0_Idle_Dummy : public RB::States::StateBase
	{
	public:
		P0_Idle_Dummy()
		{
			_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
		}

		~P0_Idle_Dummy() = default;

	public:
		void OnEnter() override
		{
			_manualAnimationUpdater.OnEnter(_spriteID);
			_manualTransitioner.OnEnter(_stateMachineID, nullptr, nullptr);
		}

		void OnUpdate() override
		{
			_manualAnimationUpdater.OnUpdate();
			_manualTransitioner.OnUpdate();
		}

		void OnFixedUpdate() override
		{
			_manualAnimationUpdater.OnFixedUpdate();
			_manualTransitioner.OnFixedUpdate();
		}

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;
		RB::States::ManualTransitioner _manualTransitioner;
	};
}