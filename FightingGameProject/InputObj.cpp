#include "InputObj.h"

namespace RB::Input
{
	InputObj::InputObj(PlayerInput playerInput, unsigned int gameFrame, unsigned int gameFrameLoop)
	{
		_playerInput = playerInput;
		_gameFrameCount = gameFrame;
		_gameFrameLoopCount = gameFrameLoop;
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

	void InputObj::SetUsedAsSpecial(bool used)
	{
		_usedAsSpecial = used;
	}

	void InputObj::SetUsedAsMovement(bool used)
	{
		_usedAsMovement = used;
	}

	bool InputObj::IsReleased()
	{
		return _isReleased;
	}

	bool InputObj::IsUsedAsSpecial()
	{
		return _usedAsSpecial;
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

	unsigned int InputObj::GetGameFrameLoopCount()
	{
		return _gameFrameLoopCount;
	}

	bool InputObj::IsPressedOnSameFrameAs(iInputObj* iObj)
	{
		if (_gameFrameCount == iObj->GetGameFrameCount() && _gameFrameLoopCount == iObj->GetGameFrameLoopCount())
		{
			return true;
		}

		return false;
	}

	bool InputObj::IsPressedEarlierThan(iInputObj* iObj)
	{
		if (_gameFrameLoopCount == iObj->GetGameFrameLoopCount())
		{
			if (_gameFrameCount < iObj->GetGameFrameCount())
			{
				return true;
			}
		}
		else if (_gameFrameLoopCount < iObj->GetGameFrameLoopCount())
		{
			return true;
		}

		return false;
	}
}