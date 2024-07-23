#pragma once

#include "../olcPixelGameEngine.h"

#include "../Players/iPlayerController.h"

#include "../Input/iInputController.h"

namespace RB::PlayerStateComponents
{
	class MoveBackOnPress
	{
	public:
		MoveBackOnPress() = default;
		~MoveBackOnPress() = default;

	public:
		void SetStateMachineID(unsigned int id);
		void OnUpdate();
		bool ProcMoveBack();

	private:
		bool _BothPressed();
		bool _MoveBackPressed();

	private:
		unsigned int _stateMachineID = 0;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _bMoveBack = false;
	};
}
