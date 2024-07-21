#pragma once

#include "../iGeneralHitStopController.h"

namespace RB::Collisions
{
	class GeneralHitStopController : public iGeneralHitStopController
	{
	public:
		GeneralHitStopController() = default;
		~GeneralHitStopController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		bool SkipFrame() override;
		void AddSkipFrames(int frames) override;

	private:
		int _skipFrames = 0;
	};
}
