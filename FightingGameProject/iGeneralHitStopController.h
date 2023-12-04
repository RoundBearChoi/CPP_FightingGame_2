#pragma once
#include <cstdint>
#include "ControllerT.h"

namespace RB::Collisions
{
	class iGeneralHitStopController : public RB::Controllers::ControllerT<iGeneralHitStopController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual bool SkipFrame() = 0;
		virtual void AddSkipFrames(uint32_t frames) = 0;
	};
}