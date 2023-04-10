#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{
		std::cout << "destroying player: " << _playerIndex << std::endl;

		delete _stateMachine;
	}

	void Player::Init(int playerIndex)
	{
		_playerIndex = playerIndex;

		_stateMachine = new RB::States::StateMachineBase();
		_stateMachine->SetID(RB::States::StateMachineID::GetID());
		_stateMachine->Init(new RB::PlayerStates::PlayerTestState());

		std::cout << "init player: " << playerIndex << std::endl;
		//std::cout << "statemachine ID: " << _stateMachine->GetID() << std::endl;
	}

	void Player::OnUpdate()
	{
		_stateMachine->OnUpdate();
	}

	void Player::OnFixedUpdate()
	{
		_stateMachine->OnFixedUpdate();
	}

	olc::vi2d Player::GetPosition()
	{
		return _position;
	}

	int Player::GetPlayerID()
	{
		return _playerIndex;
	}

	int Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(olc::vi2d moveAmount)
	{
		_position += moveAmount;
	}
}