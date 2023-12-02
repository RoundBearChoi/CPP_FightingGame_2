#pragma once
#include "ControllerBase.h"

namespace RB::Input
{
	class iSpecialMovesController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};

	extern iSpecialMovesController* SPECIAL_MOVES_CONTROLLER;
}