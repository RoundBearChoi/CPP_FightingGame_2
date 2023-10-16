#include "InputObj.h"

namespace RB::Input
{
	InputObj::InputObj(PlayerInput playerInput, olc::Key key)
	{
		_playerInput = playerInput;
		_key = key;
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

	olc::Key InputObj::GetKey()
	{
		return _key;
	}

	void InputObj::SetReleasedStatus(bool released)
	{
		_released = released;
	}
}