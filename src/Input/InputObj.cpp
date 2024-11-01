#include "InputObj.h"

namespace RB::Input
{
	InputObj::InputObj(PlayerInput playerInput, unsigned int gameFrame)
	{
		_playerInput = playerInput;
		_gameFrameCount = gameFrame;
	}

	InputObj::~InputObj()
	{

	}

	void InputObj::OnUpdate()
	{

	}

	void InputObj::OnFixedUpdate()
	{
		_fixedUpdateCount++;
	}

	PlayerInput InputObj::GetPlayerInputType()
	{
		return _playerInput;
	}

	void InputObj::SetReleasedStatus(bool released)
	{
		_isReleased = released;
	}

	void InputObj::SetUsedAsAttack(bool used)
	{
		_usedAsAttack = used;
	}

	void InputObj::SetUsedAsMovement(bool used)
	{
		_usedAsMovement = used;
	}

	bool InputObj::IsReleased()
	{
		return _isReleased;
	}

	bool InputObj::IsUsedAsAttack()
	{
		return _usedAsAttack;
	}

	bool InputObj::IsUsedAsMovement()
	{
		return _usedAsMovement;
	}

	unsigned int InputObj::GetFixedUpdateCount()
	{
		return _fixedUpdateCount;
	}

	unsigned int InputObj::GetGameFrameCount()
	{
		return _gameFrameCount;
	}

	bool InputObj::IsPressedOnSameFrameAs(iInputObj* iObj)
	{
		if (_gameFrameCount == iObj->GetGameFrameCount())
		{
			return true;
		}

		return false;
	}

	bool InputObj::IsPressedEarlierThan(iInputObj* iObj)
	{
		if (_gameFrameCount < iObj->GetGameFrameCount())
		{
			return true;
		}

		return false;
	}
}
