#pragma once
#include "iGameCamController.h"
#include "GameCam.h"
#include"olcPixelGameEngine.h"

namespace RB::Cam
{
	class GameCamController : iGameCamController
	{
	public:
		GameCamController();
		~GameCamController() override;

	public:
		olc::vi2d GetCamPos() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		GameCam _gameCam;
	};
}