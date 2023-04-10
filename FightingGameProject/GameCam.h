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
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	public:
		olc::vi2d GetPosition();

	private:
		olc::vi2d _position = { 0, 0 };
	};
}