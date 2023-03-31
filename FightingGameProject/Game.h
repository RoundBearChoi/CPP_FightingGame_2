#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"
#include "Updater.h"

namespace RB::Engine
{
	class Game : public olc::PixelGameEngine
	{
	private:
		Updater* _updater = nullptr;

	public:
		~Game()
		{
			delete _updater;
		}

		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			_updater = new Updater();

			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			olc::Pixel grayBackground(20, 20, 20);

			Clear(grayBackground);

			_updater->OnUpdate();

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