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

	vf2d Player::GetPosition()
	{
		return _position;
	}

	void Player::Move(vf2d moveAmount)
	{
		_position += moveAmount;
	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;
		
		_stateMachine = new StateMachineBase();
		_stateMachine->Init(new TestState());

		cout << "init player: " << playerIndex << endl;
	}

	void Player::OnUpdate()
	{
		_stateMachine->OnUpdate();
	}

	void Player::OnFixedUpdate()
	{
		_stateMachine->OnFixedUpdate();
	}
}