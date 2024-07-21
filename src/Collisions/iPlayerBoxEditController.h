#pragma once

#include "../ControllerT.h"

namespace RB::Collisions
{
	class iPlayerBoxEditController : public Controllers::ControllerT<iPlayerBoxEditController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}
