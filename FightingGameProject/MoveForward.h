#pragma once
#include "olcPixelGameEngine.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	class MoveForward
	{
	public:
		MoveForward() = default;
		~MoveForward() = default;

	public:
		void SetStateMachineID(size_t id);
		void OnUpdate();
		bool ProcMoveForward();

	private:
		bool _BothPressed();
		bool _MoveForwardPressed();

	private:
		size_t _stateMachineID = 0;
		olc::HWButton moveLeft;
		olc::HWButton moveRight;
		bool _moveForward = false;
	};
}