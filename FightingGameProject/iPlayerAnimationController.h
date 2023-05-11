#pragma once
#include "ControllerBase.h"

namespace RB::Render
{
	class iPlayerAnimationController : public RB::Controllers::ControllerBase
	{
	public:
		iPlayerAnimationController() = default;
		virtual ~iPlayerAnimationController() = default;
	};
}