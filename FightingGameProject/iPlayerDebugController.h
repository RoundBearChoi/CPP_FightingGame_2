#pragma once
#include "ControllerBase.h"

namespace RB::Render
{
	class iPlayerDebugController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};

	extern iPlayerDebugController* PLAYER_DEBUG_CONTROLLER;
}