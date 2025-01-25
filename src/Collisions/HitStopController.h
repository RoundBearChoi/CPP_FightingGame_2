#pragma once

#include "iHitStopController.h"

namespace RB::Collisions
{
	class HitStopController : public iHitStopController
	{
	public:
		HitStopController() = default;
		~HitStopController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		bool StopFrame() override;
		void AddStopFrames(int frames) override;

	private:
		int _stopFrames = 0;
	};
}