#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "ControllerGroup.h"

using namespace std;

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