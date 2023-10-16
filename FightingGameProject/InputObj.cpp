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

	PlayerInput InputObj::GetPlayerInput()
	{
		return _playerInput;
	}

	void InputObj::SetReleasedStatus(bool released)
	{
		_released = released;
	}

	bool InputObj::IsReleased()
	{
		return _released;
	}

	size_t InputObj::GetFixedUpdateCount()
	{
		return _fixedUpdateCount;
	}
}