#pragma once
#define OLC_PGE_APPLICATION 0
#include "olcPixelGameEngine.h"

namespace RB
{
	class Game : public olc::PixelGameEngine
	{
	private:

	public:
		~Game()
		{

		}

		bool OnUserCreate() override
		{
			sAppName = "C++FightingGame2";
		
			return true;
		}

		bool OnUserUpdate(float fElapsedTime) override
		{
			olc::Pixel grayBackground(20, 20, 20);
			Clear(grayBackground);

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