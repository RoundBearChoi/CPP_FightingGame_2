#pragma once
#include"olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "GameCam.h"
#include "CurrentCam.h"

namespace RB::Cam
{
	class GameCamController : public RB::Controllers::ControllerBase
	{
	public:
		GameCamController();
		~GameCamController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		GameCam _gameCam;
	};
}