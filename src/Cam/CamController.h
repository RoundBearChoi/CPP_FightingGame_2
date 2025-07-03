#pragma once

#include "CamObj.h"
#include "FollowPlayers.h"
#include "ZoomOnPlayers.h"

#include "iCamController.h"

namespace RB::Cam
{
	class CamController : public iCamController
	{
	public:
		CamController(float startZoom, bool allowManualControl);
		~CamController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void SetZoom(float zoom) override;
		iCamObj* GetCamObj() override;
		void AllowManualControl(bool toggle) override;

	private:
		CamObj _camObj;
		FollowPlayers _followPlayers;
		ZoomOnPlayers _zoomOnPlayers;
		bool _allowManualControl = true;
		float _startZoom = 1.0f;
	};
}
