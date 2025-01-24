#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Background
{
	#define GET_BACKGROUND_CONTROLLER static_cast<Background::iBackgroundController*>(Controllers::GetController(Controllers::ControllerType::BACKGROUND_CONTROLLER))

	class iBackgroundController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}