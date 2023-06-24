#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "PlayerID.h"
#include "PlayerInput.h"

namespace RB::Input
{
	class iInputController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
	};

	extern iInputController* INPUT_CONTROLLER;
}