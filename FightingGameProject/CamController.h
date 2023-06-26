#pragma once
#include"olcPixelGameEngine.h"
#include "CamObj.h"

#include "iCamController.h"
#include "iCamObj.h"

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

		iCamObj* GetCamObj();

	private:
		CamObj _camObj;
	};
}