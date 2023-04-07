#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{

	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;

		cout << "init player: " << playerIndex << endl;
	}

	void Player::OnUpdate()
	{

	}

	void Player::OnFixedUpdate()
	{

	}
}