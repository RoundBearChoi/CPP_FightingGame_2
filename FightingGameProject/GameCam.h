#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "GameplayControllers.h"
#include "iCam.h"

namespace RB::Cam
{
	class GameCam : public iCam
	{
	public:
		GameCam();
		~GameCam();

	public:
		olc::vi2d GetPosition() override;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		olc::vi2d _position = { -427, -427 };
		int _moveSpeed = 2;
		bool _moveLeft = false;
		bool _moveRight = false;
		bool _moveUp = false;
		bool _moveDown = false;
	};
}