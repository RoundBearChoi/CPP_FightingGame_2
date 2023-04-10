#pragma once
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "PlayerInput.h"
#include "PlayerID.h"

namespace RB::Input
{
	class iInputController : public RB::Controllers::iController
	{
	public:
		virtual olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
	};
}