#pragma once
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "ManualAnimationUpdater.h"

namespace RB::P0_States
{
	class P0_Idle_Dummy : public RB::States::StateBase
	{
	public:
		P0_Idle_Dummy()
		{
			_spriteID = RB::Sprites::SpriteID::fighter_0_idle;

			_manualAnimationUpdater.Init(_spriteID);
		}

		~P0_Idle_Dummy() = default;

	public:
		void OnUpdate() override
		{
			_manualAnimationUpdater.OnUpdate();
		}

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;
	};
}