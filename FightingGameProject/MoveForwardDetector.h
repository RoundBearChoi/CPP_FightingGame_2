#pragma once
#include "olcPixelGameEngine.h"
#include "CurrentInputController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardDetector
	{
	public:
		MoveForwardDetector() = default;
		~MoveForwardDetector() = default;

	public:
		void Init(RB::Players::iPlayer* player);
		void OnUpdate();
		bool MoveForward();

	private:
		bool _BothPressed();
		bool _MoveForwardPressed();

	private:
		RB::Players::iPlayer* _player = nullptr;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _moveForward = false;
	};
}