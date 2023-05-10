#pragma once
#include "iController.h"

namespace RB::PlayerDebug
{
	class iPlayerDebugController : public RB::Controllers::iController
	{
	public:
		iPlayerDebugController() = default;
		~iPlayerDebugController() override {};
	};
}