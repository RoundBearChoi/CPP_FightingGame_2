#pragma once
#include "olcPixelGameEngine.h"

#include "iPlayerController.h"
#include "iPlayer.h"

#include "InputController.h"

namespace RB::PlayerStateComponents
{
	class MoveBackDetector
	{
	public:
		MoveBackDetector() = default;
		~MoveBackDetector() = default;

	public:
		void SetStateMachineID(size_t id);
		void OnUpdate();
		bool MoveBack();

	private:
		bool _BothPressed();
		bool _MoveBackPressed();

	private:
		size_t _stateMachineID = 0;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _moveBack = false;
	};
}