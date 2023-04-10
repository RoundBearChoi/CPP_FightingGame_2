#include "Player.h"

namespace RB::Players
{
	Player::Player()
	{

	}

	Player::~Player()
	{
		std::cout << "destroying player: " << static_cast<int>(_playerID) << std::endl;

		delete _stateMachine;
	}

	void Player::Init(PlayerID id)
	{
		_playerID = id;

		_stateMachine = new RB::States::StateMachineBase();
		_stateMachine->SetID(RB::States::StateMachineID::GetID());
		_stateMachine->Init(new RB::PlayerStates::PlayerTestState());

		std::cout << "init player: " << static_cast<int>(_playerID) << std::endl;
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

	PlayerID Player::GetPlayerID()
	{
		return _playerID;
	}

	int Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(olc::vi2d moveAmount)
	{
		_position += moveAmount;
	}
	void Player::SetPosition(olc::vi2d pos)
	{
		_position = pos;
	}
}