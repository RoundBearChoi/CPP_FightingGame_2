#pragma once

#include "ControllerT.h"

namespace RB::Collisions
{
	class iPlayerBoxDataController : public RB::Controllers::ControllerT<iPlayerBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}