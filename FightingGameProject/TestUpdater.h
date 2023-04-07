#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "ControllerGroup.h"
#include "PlayerController.h"

using namespace std;
using namespace RB::Controllers;
using namespace RB::Players;

namespace RB::Engine
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