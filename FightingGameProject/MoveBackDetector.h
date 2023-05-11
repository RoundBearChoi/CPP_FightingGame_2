#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "InputController.h"
#include "CurrentControllers.h"

namespace RB::PlayerStateComponents
{
	class MoveBackDetector
	{
	public:
		MoveBackDetector() = default;
		~MoveBackDetector() = default;

	public:
		void Init(RB::Players::iPlayer* owner);
		void OnUpdate();
		bool MoveBack();

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