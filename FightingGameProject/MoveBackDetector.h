#pragma once
#include "olcPixelGameEngine.h"
#include "GameplayControllers.h" //temp - input controller should be similar to currentcam
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class MoveBackDetector
	{
	public:
		MoveBackDetector();
		~MoveBackDetector();

	public:
		void Init(RB::Players::iPlayer* owner);
		void OnUpdate();

	private:
		bool _BothPressed();
		bool _MoveBackPressed();

	private:
		RB::Players::iPlayer* _player = nullptr;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _moveBack = false;
	};
}