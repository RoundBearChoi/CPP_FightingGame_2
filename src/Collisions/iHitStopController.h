#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Collisions
{
	#define GET_HITSTOP_CONTROLLER static_cast<Collisions::iHitStopController*>(Controllers::GetController(Controllers::ControllerType::HITSTOP_CONTROLLER))

	class iHitStopController : public Controllers::ControllerBase
	{
	public:
		virtual bool StopFrame() = 0;
		virtual void AddStopFrames(int frames) = 0;
	};
}