#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{
		cout << "destroying player: " << _playerIndex << endl;
	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;

		cout << "init player: " << playerIndex << endl;
	}

	void Player::OnUpdate()
	{
		//cout << Time::GetDeltaTime() << endl;
	}

	void Player::OnFixedUpdate()
	{

	}
}