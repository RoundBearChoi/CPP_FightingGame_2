#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerInput.h"

namespace RB::Input
{
	class KeyBinding
	{
	public:
		KeyBinding(PlayerInput playerInput, olc::HWButton button);
		~KeyBinding();

	private:
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::HWButton _button;
	};
}