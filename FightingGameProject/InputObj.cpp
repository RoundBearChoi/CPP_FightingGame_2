#include "InputObj.h"

namespace RB::Input
{
	InputObj::InputObj(PlayerInput playerInput, size_t gameFrame, size_t gameFrameLoop)
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

	void InputObj::SetUsedStatus(bool used)
	{
		_isUsed = used;
	}

	bool InputObj::IsReleased()
	{
		return _isReleased;
	}

	bool InputObj::IsUsed()
	{
		return _isUsed;
	}

	size_t InputObj::GetFixedUpdateCount()
	{
		return _fixedUpdateCount;
	}

	size_t InputObj::GetGameFrameCount()
	{
		return _gameFrameCount;
	}

	size_t InputObj::GetGameFrameLoopCount()
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