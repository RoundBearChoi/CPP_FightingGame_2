#pragma once
#include "CamObj.h"
#include "iCamObj.h"
#include "iCamController.h"
#include "FollowPlayers.h"
#include "ZoomOnPlayers.h"

namespace RB::Cam
{
	class CamController : public iCamController
	{
	public:
		CamController() = default;
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
	};
}