#pragma once

#include "../ControllerT.h"

namespace RB::Render
{
	class iPlayerDebugController : public RB::Controllers::ControllerT<iPlayerDebugController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void RenderPlayerBox(bool render) = 0;
	};
}
