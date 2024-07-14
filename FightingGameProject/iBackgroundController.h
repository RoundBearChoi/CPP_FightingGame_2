#pragma once

#include "ControllerT.h"

namespace RB::Background
{
	class iBackgroundController : public RB::Controllers::ControllerT<iBackgroundController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}
