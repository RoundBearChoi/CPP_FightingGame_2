#include "GameCamController.h"

namespace RB::Cam
{
	GameCamController::GameCamController()
	{
		SetHash(typeid(this).name());
	}

	void GameCamController::Init()
	{
		_gameCam.Init();

		RB::Cam::CurrentCam::SetCurrentCam(&_gameCam);
	}

	void GameCamController::OnUpdate()
	{
		_gameCam.OnUpdate();
	}

	void GameCamController::OnFixedUpdate()
	{
		_gameCam.OnFixedUpdate();
	}
}