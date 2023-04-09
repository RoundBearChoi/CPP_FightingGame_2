#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "Time.h"
#include "FixedTimer.h"
#include "ControllerGroup.h"

namespace RB::Engine
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updater _updater;
		RB::Frames::FixedTimer _timer;

	public:
		bool OnUserCreate() override
		{
			cout << "OnUserCreate (Game)" << endl;

			sAppName = "C++FightingGame2";
		
			_updater.Init();

			ControllerGroup::Init();
			RB::Frames::Time::ClearFixedDeltaTime();

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
			RB::Frames::Time::SetDeltaTime(fElapsedTime);
			RB::Frames::Time::AddFixedDeltaTime();

			olc::Pixel grayBackground(20, 20, 20);
			Clear(grayBackground);

			_updater.OnUpdate();

			if (_timer.DoFixedUpdate())
			{
				_updater.OnFixedUpdate();

				RB::Frames::Time::ClearFixedDeltaTime();
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