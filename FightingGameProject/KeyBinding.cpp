#include "KeyBinding.h"

namespace RB::Input
{
	KeyBinding::KeyBinding(PlayerInput playerInput, olc::HWButton button)
	{
		_playerInput = playerInput;
		_button = button;
	}

	KeyBinding::~KeyBinding()
	{

	}
}