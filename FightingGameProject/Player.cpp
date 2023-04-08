#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{
		cout << "destroying player: " << _playerIndex << endl;

		delete _stateMachine;
	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;
		
		_stateMachine = new StateMachineObj();
		_stateMachine->Init(new StateBase());

		cout << "init player: " << playerIndex << endl;
	}

	void Player::OnUpdate()
	{
		//cout << Time::GetDeltaTime() << endl;
	}

	void Player::OnFixedUpdate()
	{
		//cout << Time::GetFixedDeltaTime() << endl;
	}
}