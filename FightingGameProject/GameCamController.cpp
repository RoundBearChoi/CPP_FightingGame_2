#include "GameCamController.h"

namespace RB::Cam
{
	GameCamController::GameCamController()
	{

	}

	GameCamController::~GameCamController()
	{

	}

	olc::vi2d GameCamController::GetCamPos()
	{
		return _gameCam.GetPosition();
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