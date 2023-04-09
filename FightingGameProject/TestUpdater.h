#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "iUpdaterObj.h"
#include "ControllerGroup.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "GameplayControllers.h"

using namespace std;
using namespace RB::Engine;
using namespace RB::Controllers;
using namespace RB::Players;

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