#pragma once

#include "olcPixelGameEngine.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnPress
	{
	public:
		MoveForwardOnPress() = default;
		~MoveForwardOnPress() = default;

	public:
		void SetStateMachineID(unsigned int id);
		void OnUpdate();
		bool ProcMoveForward();

	private:
		bool _BothPressed();
		bool _MoveForwardPressed();

	private:
		unsigned int _stateMachineID = 0;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _bMoveForward = false;
	};
}
