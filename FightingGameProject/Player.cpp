#include "Player.h"

namespace RB::Players
{
	Player::~Player()
	{
		std::cout << "destroying player: " << static_cast<int>(_playerID) << std::endl;

		delete _stateMachine;
	}

	void Player::Init(PlayerID id, RB::States::iState* firstPlayerState)
	{
		if (firstPlayerState == nullptr)
		{
			std::cout << "WARNING: firstPlayerState is nullptr" << std::endl;
		}
		else
		{
			_playerID = id;

			_stateMachine = new RB::States::StateMachineBase();
			_stateMachine->Init(firstPlayerState);

			_playerCollider.Init(this);
			_airMomentum.Init(this);

			std::cout << "init player: " << static_cast<int>(_playerID) << std::endl;
		}
	}

	void Player::OnUpdate()
	{
		//_getter_playerController.OnUpdate();

		//if (_getter_playerController.GetController() == nullptr)
		//{
		//	return;
		//}

		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return;
		}

		_stateMachine->OnUpdate();

		_playerCollider.OnUpdate();
	}

	void Player::OnFixedUpdate()
	{
		_stateMachine->OnFixedUpdate();

		_playerCollider.OnFixedUpdate();
	}

	PlayerID Player::GetPlayerID()
	{
		return _playerID;
	}

	bool Player::OtherPlayerIsOnRightSide()
	{
		//if (_getter_playerController.GetController() == nullptr)
		//{
		//	return true;
		//}

		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return true;
		}

		iPlayer* other = RB::Players::PlayerController::PTR->GetOtherPlayer(this); //_getter_playerController.GetController()->GetOtherPlayer(this);

		if (other == nullptr)
		{
			return true;
		}

		if (_position.x < other->GetPosition().x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	RB::States::iStateMachine* Player::GetStateMachine()
	{
		return _stateMachine;
	}

	size_t Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(olc::vi2d moveAmount)
	{
		_position += moveAmount;
	}

	olc::vi2d Player::GetPosition()
	{
		return _position;
	}

	void Player::SetPosition(olc::vi2d pos)
	{
		_position = pos;
	}

	void Player::SetManualAnimationUpdate(bool manual)
	{
		_manualAnimationUpdate = manual;
	}

	bool Player::ManualAnimationUpdate()
	{
		return _manualAnimationUpdate;
	}

	olc::vi2d Player::GetPlayerBox()
	{
		return _playerCollider.GetPlayerBox();
	}

	RB::Collisions::AABB& Player::GetAABB()
	{
		return _playerCollider.GetAABB();
	}

	bool Player::IsCollidingAgainstOtherPlayer()
	{
		return _playerCollider.IsColliding();
	}

	void Player::SetAirMomentum(olc::vf2d momentum)
	{
		_airMomentum.SetMomentum(momentum);
	}

	void Player::AddMomentum(olc::vf2d momentum)
	{
		_airMomentum.AddMomentum(momentum);
	}

	olc::vf2d Player::GetAirMomentum()
	{
		return _airMomentum.GetMomentum();
	}
}