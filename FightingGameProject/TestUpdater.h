#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "iUpdaterObj.h"
#include "ControllerGroup.h"
#include "GameplayControllers.h"
#include "InputController.h"
#include "BoxRenderController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "GameCamController.h"

namespace RB::Updaters
{
	class TestUpdater : public iUpdaterObj
	{
	public:
		TestUpdater();
		~TestUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}