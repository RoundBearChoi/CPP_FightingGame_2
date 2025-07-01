#pragma once

#include "../olcPixelGameEngine.h"

#include "PlayerInput.h"

#include "../Players/PlayerID.h"

namespace RB::Input
{
	class KeyBinding
	{
	public:
		KeyBinding(Players::PlayerID playerID, PlayerInput playerInput, olc::Key key);
		~KeyBinding() = default;

	public:
		Players::PlayerID GetPlayerID();
		Input::PlayerInput GetPlayerInput();
		olc::Key GetKey();

	private:
		Players::PlayerID _playerID = Players::PlayerID::NONE;
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::Key _key = olc::NONE;
	};
}
