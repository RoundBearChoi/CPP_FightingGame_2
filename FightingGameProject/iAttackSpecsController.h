#pragma once
#include "ControllerT.h"

namespace RB::Collisions
{
	class iAttackSpecsController : public RB::Controllers::ControllerT<iAttackSpecsController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}