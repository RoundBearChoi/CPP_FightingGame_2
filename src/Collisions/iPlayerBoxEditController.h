#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::Collisions
{
	#define GET_PLAYER_BOX_EDIT_CONTROLLER static_cast<Collisions::iPlayerBoxEditController*>(Controllers::GetController(Controllers::ControllerType::PLAYER_BOX_EDIT_CONTROLLER))

	class iPlayerBoxEditController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}