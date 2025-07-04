#include "CamController.h"

namespace RB::Cam
{
	CamController::CamController(float startZoom, bool allowManualControl)
	{
		_startZoom = startZoom;
		_allowManualControl = allowManualControl;
	}

	void CamController::Init()
	{
		_camObj.Init();

		_followPlayers.Init(&_camObj);
		_zoomOnPlayers.Init();

		_camObj.SetZoom(_startZoom);
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
			_zoomOnPlayers.OnFixedUpdate();
		}
	}

	void CamController::SetZoom(float zoom)
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
