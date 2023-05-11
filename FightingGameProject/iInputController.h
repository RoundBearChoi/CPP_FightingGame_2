#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "PlayerInput.h"
#include "PlayerID.h"

namespace RB::Input
{
	class iInputController : public RB::Controllers::ControllerBase
	{
	public:
		iInputController() = default;
		~iInputController() override {};

		virtual olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
	};
}