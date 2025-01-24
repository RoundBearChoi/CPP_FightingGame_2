#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Collisions
{
	#define GET_GENERAL_HITSTOP_CONTROLLER static_cast<Collisions::iGeneralHitStopController*>(Controllers::GetController(Controllers::ControllerType::GENERAL_HITSTOP_CONTROLLER))

	class iGeneralHitStopController : public Controllers::ControllerBase
	{
	public:
		virtual bool SkipFrame() = 0;
		virtual void AddSkipFrames(int frames) = 0;
	};
}