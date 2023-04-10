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

	olc::vi2d GameCamController::GetRelativePos(olc::vi2d pos)
	{
		olc::vi2d rel = pos - _gameCam.GetPosition();

		return rel;
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