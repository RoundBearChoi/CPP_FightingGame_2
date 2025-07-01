#pragma once

#include "../Controllers/ControllerBase.h"

namespace RB::HBox
{
	#define GET_HB_MENU_CONTROLLER static_cast<HBox::iHBMenuController*>(Controllers::GetController(Controllers::ControllerType::HB_MENU_CONTROLLER))

	class iHBMenuController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void ShowNotification() = 0;
		virtual void SetPageTitle(std::string title) = 0;
	};
}
