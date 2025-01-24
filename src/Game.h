#pragma once

#include "AllocationCount.h"
#define OLC_PGE_APPLICATION 0

#include <iostream>

#include "olcPixelGameEngine.h"

#include "GameFrame.h"
#include "Time.h"
#include "FixedTimer.h"
#include "UpdateCounter.h"
#include "DisplaySize.h"

#include "Render/RenderLayerType.h"
#include "Updaters/CurrentPlayground.h"
#include "Updaters/Playground.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updaters::iPlayground* _playground = nullptr;
		FixedTimer _timer;
		UpdateCounter _updateCounter;

	public:
		Game()
		{

		}

		~Game() override
		{
			delete _playground;

			std::cout << std::endl;
			std::cout << "alloc count after deleting playground: " << numObjBeforePlayground << std::endl;
			std::cout << std::endl;
		}

		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			std::cout << "alloc count before creating playground: " << numObjects << std::endl << std::endl;
			numObjBeforePlayground = numObjects;

			_playground = new Updaters::Playground();

			Updaters::ptrCurrentPlayground = _playground;

			_playground->Init();

			Render::CreateLayers();

			return true;
		}

		bool OnUserDestroy() override
		{
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			if (_timer.DoFixedUpdate())
			{
				_playground->OnFixedUpdate();

				AddGameFrame();
			}

			Render::ClearLayers();

			Time::SetDeltaTime(fElapsedTime);

			_playground->OnUpdate();
			_updateCounter.OnUpdate();

			return true;
		}

		void Run()
		{
			if (Construct(displayWidth, displayHeight, 1, 1, false, false, false))
			{
				std::cout << "current working directory: " << std::filesystem::current_path()  << std::endl;
				std::cout << std::endl;

				Start();
			}
		}
	};
}