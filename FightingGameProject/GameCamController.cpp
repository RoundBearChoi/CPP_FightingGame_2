#include "GameCamController.h"

namespace RB::Cam
{
	GameCamController::GameCamController()
	{

	}

	GameCamController::~GameCamController()
	{

	}

	void GameCamController::Init()
	{
		_gameCam.Init();
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