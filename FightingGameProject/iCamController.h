#pragma once
#include "ControllerBase.h"

#include "iCamObj.h"

namespace RB::Cam
{
	class iCamController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void SetZoom(float_t zoom) = 0;
		virtual iCamObj* GetCamObj() = 0;
	};

	extern iCamController* CAM_CONTROLLER;
}