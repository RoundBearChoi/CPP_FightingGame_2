#pragma once
#include "ControllerBase.h"

namespace RB::HBox
{
	class iMenuController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void ShowNotification() = 0;
	};

	extern iMenuController* MENU_CONTROLLER;
}
