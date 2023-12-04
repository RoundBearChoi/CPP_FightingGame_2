#pragma once
//#include "ControllerBase.h"
#include "ControllerT.h"

namespace RB::Background
{
	class iBackgroundController : public RB::Controllers::ControllerT<iBackgroundController> //public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};

	//extern iBackgroundController* BACKGROUND_CONTROLLER;
}