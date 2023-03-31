#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "Updaters.h"

namespace RB::Engine
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updaters* _updaters = nullptr;

	public:
		~Game()
		{
			delete _updaters;
		}

		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_updaters = new Updaters();

			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			olc::Pixel grayBackground(20, 20, 20);

			Clear(grayBackground);

			_updaters->OnUpdate();

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