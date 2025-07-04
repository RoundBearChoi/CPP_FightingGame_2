#include "Player.h"

namespace RB::Players
{
	Player::~Player()
	{
		//std::cout << "destroying player: " << static_cast<int>(_playerID) << std::endl;

		delete _stateMachine;

		_stateMachine = nullptr;
	}

	void Player::Init(PLAYER_TYPE id, RB::States::iState* firstPlayerState)
	{
		if (firstPlayerState == nullptr)
		{
			//std::cout << "WARNING: firstPlayerState is nullptr" << std::endl;
		}
		else
		{
			_playerID = id;

			_stateMachine = new RB::States::StateMachineBase();
			_stateMachine->Init(firstPlayerState);

			_playerCollider.Init(this);

			//std::cout << "init player: " << static_cast<int>(_playerID) << std::endl;
		}
	}

	void Player::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
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

	PLAYER_TYPE Player::GetPLAYER_TYPE()
	{
		return _playerID;
	}

	void Player::SetCharacterType(CharacterType type)
	{
		_characterType = type;
	}

	CharacterType Player::GetCharacterType()
	{
		return _characterType;
	}

	iPlayerCollider* Player::GetPlayerCollider()
	{
		return &_playerCollider;
	}

	int Player::GetPLAYER_TYPE_int()
	{
		if (_playerID._value == Players::PLAYER_TYPE::PLAYER_1)
		{
			return 1;
		}
		else if (_playerID._value == Players::PLAYER_TYPE::PLAYER_2)
		{
			return 2;
		}

		return 0;
	}

	// This is different from OtherPlayerIsOnRightSide. You can be facing right side while the enemy is on your left
	bool Player::IsFacingRight()
	{
		if (_dirIsFixedDuringState)
		{
			return _initiallyFacingRight;
		}

		return OtherPlayerIsOnRightSide();
	}

	bool Player::OtherPlayerIsOnRightSide()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return true;
		}

		iPlayer* other = playerController->GetOtherPlayer(this);

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

	void Player::MarkCrouching(bool crouching)
	{
		_isCrouching = crouching;
	}

	bool Player::IsCrouching()
	{
		return _isCrouching;
	}

	RB::States::iStateMachine* Player::GetStateMachine()
	{
		return _stateMachine;
	}

	unsigned int Player::GetStateMachineID()
	{
		return _stateMachine->GetID();
	}

	void Player::Move(RB::Vector2 moveAmount)
	{
		_position += moveAmount;
	}

	RB::Vector2 Player::GetPosition()
	{
		return _position;
	}

	void Player::SetPosition(RB::Vector2 pos)
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

	void Player::SetWincingStatus(bool wincing)
	{
		_isWincing = wincing;
	}

	bool Player::IsWincing()
	{
		return _isWincing;
	}

	void Player::FixDirDuringState(bool fix)
	{
		_dirIsFixedDuringState = fix;
	}

	void Player::SetIsInSpecialMoveStatus(bool specialMove)
	{
		_isInSpecialMoveState = specialMove;
	}

	bool Player::IsInSpecialMoveStatus()
	{
		return _isInSpecialMoveState;
	}

	void Player::AddHP(int amount)
	{
		//std::cout << std::endl;
		//std::cout << "player " << GetPLAYER_TYPE_int()  << " | adding hp " << amount;

		_hp += amount;

		//std::cout << " | result hp: " << _hp << std::endl;
	}

	int Player::GetHP()
	{
		return _hp;
	}
}
