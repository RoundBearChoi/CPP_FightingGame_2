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

		bool SkipFrame() override;
		void AddSkipFrames(int frames) override;

	private:
		int _skipFrames = 0;
	};
}