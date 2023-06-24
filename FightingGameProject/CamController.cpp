#include "CamController.h"

namespace RB::Cam
{
	CamController::CamController()
	{
		SetHash(typeid(*this));

		CAM_CONTROLLER = this;
	}

	CamController::~CamController()
	{
		CAM_CONTROLLER = nullptr;
	}

	void CamController::Init()
	{
		_camObj.Init();
	}

	void CamController::OnUpdate()
	{
		_camObj.OnUpdate();
	}

	void CamController::OnFixedUpdate()
	{
		_camObj.OnFixedUpdate();
	}

	CamObj* CamController::GetCamObj()
	{
		return &_camObj;
	}
}