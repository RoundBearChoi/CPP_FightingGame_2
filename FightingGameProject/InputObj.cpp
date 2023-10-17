#include "InputObj.h"

namespace RB::Input
{
	InputObj::InputObj(PlayerInput playerInput)
	{
		_playerInput = playerInput;
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
}