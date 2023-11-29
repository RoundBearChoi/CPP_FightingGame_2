#pragma once
#define OLC_PGE_APPLICATION 0

#include "olcPixelGameEngine.h"
#include "AllocationCount.h"
#include "GameFrame.h"
#include "Updater.h"
#include "Time.h"
#include "FixedTimer.h"
#include "DisplaySize.h"
#include "ActiveControllers.h"
#include "jsonExample.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		RB::Updaters::Updater _updater;
		RB::Frames::FixedTimer _timer;

	public:
		bool OnUserCreate() override
		{
			std::cout << std::endl;
			std::cout << "OnUserCreate.." << std::endl;

			sAppName = "C++FightingGame2";
		
			_updater.Init();

			RB::Frames::Time::ResetFixedDeltaTime();

			RB::JSON::example{}.example1();

			return true;
		}

		bool OnUserDestroy() override
		{
			return true;
		}

		~Game()
		{
			showAllocationCount = true;

			std::cout << std::endl;
			std::cout << "destroying Game.." << std::endl;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			RB::Frames::Time::SetDeltaTime(fElapsedTime);
			RB::Frames::Time::AddFixedDeltaTime();

			Clear(olc::Pixel{ 20, 20, 20});

			_updater.OnUpdate();
			RB::AddGameFrame();

			if (_timer.DoFixedUpdate())
			{
				_updater.OnFixedUpdate();

				RB::Frames::Time::ResetFixedDeltaTime();
			}

			return true;
		}

		void Run()
		{
			if (Construct(displayWidth, displayHeight, 1, 1))
			{
				Start();
			}
		}
	};
}