#pragma once
#include "iController.h"

namespace RB::Render
{
	class iPlayerAnimationController : public RB::Controllers::iController
	{
	public:
		iPlayerAnimationController() = default;
		virtual ~iPlayerAnimationController() = default;
	};
}