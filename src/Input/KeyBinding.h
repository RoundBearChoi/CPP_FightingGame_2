#pragma once

#include "../olcPixelGameEngine.h"

#include "PlayerInput.h"

#include "../Players/PlayerType.h"

namespace RB::Input
{
	class KeyBinding
	{
	public:
		KeyBinding(Players::PLAYER_TYPE playerID, PlayerInput playerInput, olc::Key key);
		~KeyBinding() = default;

	public:
		Players::PLAYER_TYPE GetPLAYER_TYPE();
		Input::PlayerInput GetPlayerInput();
		olc::Key GetKey();

	private:
		Players::PLAYER_TYPE _playerID = Players::PLAYER_TYPE::NONE;
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::Key _key = olc::NONE;
	};
}
