#include "CamController.h"

namespace RB::Cam
{
	CamController::CamController()
	{
		SetHash(typeid(*this));
	}

	void CamController::Init()
	{
		_camObj.Init();

		RB::Cam::CurrentCam::SetCurrentCam(&_camObj);
	}

	void CamController::OnUpdate()
	{
		_camObj.OnUpdate();
	}

	void CamController::OnFixedUpdate()
	{
		_camObj.OnFixedUpdate();
	}
}