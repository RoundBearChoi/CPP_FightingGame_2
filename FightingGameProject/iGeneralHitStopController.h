#pragma once
#include <cstdint>
#include "ControllerBase.h"

namespace RB::Collisions
{
	class iGeneralHitStopController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual bool SkipFrame() = 0;
		virtual void AddSkipFrames(uint32_t frames) = 0;
	};

	extern iGeneralHitStopController* GENERAL_HIT_STOP_CONTROLLER;
}