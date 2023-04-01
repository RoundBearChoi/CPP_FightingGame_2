#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "Timer.h"

namespace RB::Engine
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updater _updater;
		Timer _timer;

	public:
		~Game()
		{

		}

		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_updater.Init();

			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			olc::Pixel grayBackground(20, 20, 20);

			Clear(grayBackground);

			_updater.OnUpdate();

			if (_timer.UpdateTime(fElapsedTime))
			{
				_updater.OnFixedUpdate();
			}

			_timer.ShowFixedUpdateCount();

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