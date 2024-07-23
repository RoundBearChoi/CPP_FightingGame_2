#pragma once

#include "../Controllers/ControllerT.h"

namespace RB::HBox
{
	class iHBMenuController : public RB::Controllers::ControllerT<iHBMenuController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void ShowNotification() = 0;
		virtual void SetPageTitle(std::string title) = 0;
	};
}
