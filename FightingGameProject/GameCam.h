#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Cam
{
	class GameCam
	{
	public:
		GameCam();
		~GameCam();

	public:
		olc::vi2d GetPosition();

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		olc::vi2d _position = { 0, 0 };
	};
}