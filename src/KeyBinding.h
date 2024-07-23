#pragma once

#include "olcPixelGameEngine.h"

#include "PlayerInput.h"
#include "Players/PlayerID.h"

namespace RB::Input
{
	class KeyBinding
	{
	public:
		KeyBinding(RB::Players::PlayerID playerID, PlayerInput playerInput, olc::Key key);
		~KeyBinding() = default;

	public:
		RB::Players::PlayerID GetPlayerID();
		RB::Input::PlayerInput GetPlayerInput();
		olc::Key GetKey();

	private:
		RB::Players::PlayerID _playerID = RB::Players::PlayerID::NONE;
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::Key _key = olc::NONE;
	};
}