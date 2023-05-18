#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "InputController.h"
#include "PlayerController.h"

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

	private:
		RB::Controllers::ControllerGetter<RB::Input::InputController> _getter_inputController;
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
	};
}