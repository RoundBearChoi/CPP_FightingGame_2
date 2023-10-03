#pragma once
#include "olcPixelGameEngine.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	class MoveBackOnPress
	{
	public:
		MoveBackOnPress() = default;
		~MoveBackOnPress() = default;

	public:
		void SetStateMachineID(size_t id);
		void OnUpdate();
		bool ProcMoveBack();

	private:
		bool _BothPressed();
		bool _MoveBackPressed();

	private:
		size_t _stateMachineID = 0;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _bMoveBack = false;
	};
}