#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{
		std::cout << "destroying player: " << _playerIndex << endl;

		delete _stateMachine;
	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;

		_stateMachine = new RB::States::StateMachineBase();
		_stateMachine->Init(new PlayerTestState());
		_stateMachine->SetID(RB::States::StateMachineID::GetID());

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

	int Player::GetPlayerIndex()
	{
		return _playerIndex;
	}

	int Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(vi2d moveAmount)
	{
		_position += moveAmount;
	}
}