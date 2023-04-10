#pragma once
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "PlayerInput.h"

namespace RB::Input
{
	class iInputController : public RB::Controllers::iController
	{
	public:
		virtual olc::HWButton GetButton(Input::PlayerInput playerInput) = 0;
	};
}