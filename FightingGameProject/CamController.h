#pragma once
#include"olcPixelGameEngine.h"
#include "CamObj.h"

#include "iCamController.h"
#include "iCamObj.h"

#include "FollowPlayers.h"

namespace RB::Cam
{
	class CamController : public iCamController
	{
	public:
		CamController();
		~CamController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void SetZoom(float_t zoom) override;
		iCamObj* GetCamObj() override;
		void AllowManualControl(bool toggle) override;

	private:
		CamObj _camObj;
		FollowPlayers _followPlayers;
		bool _allowManualControl = true;
	};
}