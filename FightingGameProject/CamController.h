#pragma once
#include"olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "CamObj.h"

namespace RB::Cam
{
	class CamController : public RB::Controllers::ControllerBase
	{
	public:
		CamController();
		~CamController() override;
		static inline CamController* PTR = nullptr;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		CamObj* GetCamObj();

	private:
		CamObj _camObj;
	};
}