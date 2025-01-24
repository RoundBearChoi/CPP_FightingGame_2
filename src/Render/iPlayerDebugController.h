#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Render
{
	#define GET_PLAYER_DEBUG_CONTROLLER static_cast<RB::Render::iPlayerDebugController*>(RB::Controllers::GetController(Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER))

	class iPlayerDebugController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void RenderPlayerBox(bool render) = 0;
		virtual void RenderPlayerHP(bool render) = 0;
		virtual void RenderInput(bool render) = 0;
	};
}