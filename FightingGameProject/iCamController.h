#pragma once
#include "ControllerBase.h"
#include "CamObj.h"

namespace RB::Cam
{
	class iCamController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual CamObj* GetCamObj() = 0;
	};

	extern iCamController* CAM_CONTROLLER;
}