#pragma once
#include "ControllerT.h"

namespace RB::HBox
{
	class iMenuController : public RB::Controllers::ControllerT<iMenuController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void ShowNotification() = 0;
	};
}