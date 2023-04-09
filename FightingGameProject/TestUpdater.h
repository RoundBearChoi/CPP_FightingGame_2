#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "iUpdaterObj.h"
#include "ControllerGroup.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "GameplayControllers.h"

namespace RB::Updaters
{
	class TestUpdater : public RB::Engine::iUpdaterObj
	{
	public:
		TestUpdater();
		~TestUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}