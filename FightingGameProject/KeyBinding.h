#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerInput.h"

namespace RB::Input
{
	class KeyBinding
	{
	public:
		KeyBinding(int playerID, PlayerInput playerInput, olc::Key key);
		~KeyBinding();

	private:
		int _playerID = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::Key _key = olc::NONE;
	};
}