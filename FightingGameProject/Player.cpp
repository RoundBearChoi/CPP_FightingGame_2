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

		_stateMachine = new StateMachineBase();
		_stateMachine->Init(new PlayerTestState());
		_stateMachine->SetID(StateMachineID::GetID());

		cout << "init player: " << playerIndex << endl;
		cout << "statemachine ID: " << _stateMachine->GetID() << endl;
	}

	void Player::OnUpdate()
	{
		_stateMachine->OnUpdate();
	}

	void Player::OnFixedUpdate()
	{
		_stateMachine->OnFixedUpdate();
	}

	vi2d Player::GetPosition()
	{
		return _position;
	}

	int Player::GetIndex()
	{
		return _playerIndex;
	}

	void Player::Move(vi2d moveAmount)
	{
		_position += moveAmount;
	}
}