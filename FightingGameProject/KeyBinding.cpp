#include "KeyBinding.h"

namespace RB::Input
{
	KeyBinding::KeyBinding(RB::Players::PlayerID playerID, PlayerInput playerInput, olc::Key key)
	{
		_playerID = playerID;
		_playerInput = playerInput;
		_key = key;
	}

	KeyBinding::~KeyBinding()
	{

	}

	RB::Players::PlayerID KeyBinding::GetPlayerID()
	{
		return _playerID;
	}

	RB::Input::PlayerInput KeyBinding::GetPlayerInput()
	{
		return _playerInput;
	}

	olc::Key KeyBinding::GetKey()
	{
		return _key;
	}
}