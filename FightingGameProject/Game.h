#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "Timer.h"
#include "Time.h"
#include "ControllerGroup.h"

using namespace RB::Controllers;
using namespace RB::Frames;

namespace RB::Engine
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updater _updater;
		Timer _timer;

	public:
		bool OnUserCreate() override
		{
			cout << "OnUserCreate (Game)" << endl;

			sAppName = "C++FightingGame2";
		
			_updater.Init();

			ControllerGroup::Init();

			return true;
		}

		~Game()
		{
			cout << endl;
			cout << "destroying Game" << endl;

			ControllerGroup::OnEnd();
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			Time::SetDeltaTime(fElapsedTime);
			olc::Pixel grayBackground(20, 20, 20);
			Clear(grayBackground);

			_updater.OnUpdate();

			if (_timer.DoFixedUpdate())
			{
				_updater.OnFixedUpdate();
			}

			return true;
		}

		void Run()
		{
			if (Construct(854, 480, 1, 1))
			{
				Start();
			}
		}
	};
}