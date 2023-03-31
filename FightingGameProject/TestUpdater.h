#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdater.h"

namespace RB::Engine
{
	class TestUpdater : public iUpdater
	{
	public:
		TestUpdater();
		~TestUpdater() override;

		void Init() override;
		void OnUpdate() override;
	};
}