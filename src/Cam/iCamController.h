#pragma once

#include "iCamObj.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Cam
{
	#define GET_CAM_CONTROLLER static_cast<Cam::iCamController*>(Controllers::GetController(Controllers::ControllerType::CAM_CONTROLLER))

	class iCamController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void SetZoom(float zoom) = 0;
		virtual iCamObj* GetCamObj() = 0;
		virtual void AllowManualControl(bool toggle) = 0;
	};
}