#pragma once
#include"olcPixelGameEngine.h"
#include "iGameCamController.h"
#include "GameCam.h"
#include "CurrentCam.h"

namespace RB::Cam
{
	class GameCamController : iGameCamController
	{
	public:
		GameCamController();
		~GameCamController() override;

	public:
		//olc::vi2d GetCamPos() override;
		//olc::vi2d GetRelativePos(olc::vi2d pos) override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		GameCam _gameCam;
	};
}