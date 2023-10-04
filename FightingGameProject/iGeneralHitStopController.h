#pragma once
#include "ControllerBase.h"

namespace RB::Collisions
{
	class iGeneralHitStopController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	};

	extern iGeneralHitStopController* GENERAL_HIT_STOP_CONTROLLER;
}