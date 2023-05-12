#pragma once
#include"olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "CamObj.h"
#include "CurrentCam.h"

namespace RB::Cam
{
	class CamController : public RB::Controllers::ControllerBase
	{
	public:
		CamController();
		~CamController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		CamObj _camObj;
	};
}