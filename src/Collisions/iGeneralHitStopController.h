#pragma once

#include "../Controllers/ControllerT.h"

namespace RB::Collisions
{
	class iGeneralHitStopController : public Controllers::ControllerT<iGeneralHitStopController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual bool SkipFrame() = 0;
		virtual void AddSkipFrames(int frames) = 0;
	};
}