#pragma once
#include "iGameCamController.h"
#include "GameCam.h"

namespace RB::Cam
{
	class GameCamController : iGameCamController
	{
	public:
		GameCamController();
		~GameCamController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		GameCam _gameCam;
	};
}