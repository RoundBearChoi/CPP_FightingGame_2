#pragma once

#include "iCamObj.h"

#include "../ControllerT.h"

namespace RB::Cam
{
	class iCamController : public RB::Controllers::ControllerT<iCamController>
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
