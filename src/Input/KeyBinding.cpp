#include "KeyBinding.h"

namespace RB::Input
{
	KeyBinding::KeyBinding(Players::PLAYER_TYPE playerID, PlayerInput playerInput, olc::Key key)
	{
		_playerID = playerID;
		_playerInput = playerInput;
		_key = key;
	}

	Players::PLAYER_TYPE KeyBinding::GetPLAYER_TYPE()
	{
		return _playerID;
	}

	Input::PlayerInput KeyBinding::GetPlayerInput()
	{
		return _playerInput;
	}

	olc::Key KeyBinding::GetKey()
	{
		return _key;
	}
}
