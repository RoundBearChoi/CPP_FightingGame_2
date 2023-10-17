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

		_followPlayers.Init(&_camObj);
	}

	void CamController::OnUpdate()
	{
		if (_allowManualControl)
		{
			_camObj.ManualUpdate();
		}
		else
		{
			_followPlayers.OnUpdate();
		}
	}

	void CamController::OnFixedUpdate()
	{
		if (_allowManualControl)
		{
			_camObj.ManualFixedUpdate();
		}
		else
		{
			_followPlayers.OnFixedUpdate();
		}
	}

	void CamController::SetZoom(float_t zoom)
	{
		_camObj.SetZoom(zoom);
	}

	iCamObj* CamController::GetCamObj()
	{
		return &_camObj;
	}

	void CamController::AllowManualControl(bool toggle)
	{
		_allowManualControl = toggle;
	}
}