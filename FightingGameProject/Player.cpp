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

			std::cout << "init player: " << static_cast<int>(_playerID) << std::endl;
		}
	}

	void Player::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
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

	int Player::GetPlayerID_int()
	{
		if (_playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return 1;
		}
		else if (_playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return 2;
		}

		return 0;
	}

	bool Player::IsFacingRight()
	{
		if (_position.y < -0.1f)
		{
			return _initiallyFacingRight;
		}

		return OtherPlayerIsOnRightSide();
	}

	bool Player::OtherPlayerIsOnRightSide()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return true;
		}

		iPlayer* other = RB::Players::PLAYER_CONTROLLER->GetOtherPlayer(this);

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

	bool Player::InitiallyFacingRight()
	{
		return false;
	}

	void Player::InitiallyFacingRight(bool initiallyFacingRight)
	{
		_initiallyFacingRight = initiallyFacingRight;
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

	RB::Collisions::AABB& Player::UpdateAABBOnPlayerPos()
	{
		return _playerCollider.UpdateAABBOnPlayerPos();
	}

	bool Player::IsCollidingAgainstOtherPlayer()
	{
		return _playerCollider.IsColliding();
	}
}