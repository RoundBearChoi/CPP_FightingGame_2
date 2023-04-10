#include "KeyBinding.h"

namespace RB::Input
{
	KeyBinding::KeyBinding(int playerID, PlayerInput playerInput, olc::Key key)
	{
		_playerID = playerID;
		_playerInput = playerInput;
		_key = key;
	}

	KeyBinding::~KeyBinding()
	{

	}
}