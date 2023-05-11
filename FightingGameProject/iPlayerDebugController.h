#pragma once
#include "ControllerBase.h"

namespace RB::PlayerDebug
{
	class iPlayerDebugController : public RB::Controllers::ControllerBase
	{
	public:
		iPlayerDebugController() = default;
		~iPlayerDebugController() override {};
	};
}