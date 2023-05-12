#include "CamObj.h"

namespace RB::Cam
{
	olc::vi2d CamObj::GetPosition()
	{
		return _position;
	}

	void CamObj::Init()
	{
		_inputController = RB::Controllers::Controllers::GetController<RB::Input::InputController>();
	}

	void CamObj::OnUpdate()
	{
		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = _inputController->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = _inputController->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = _inputController->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = _inputController->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		if (moveUp.bHeld && moveDown.bHeld)
		{
			// do nothing
		}
		else if (moveUp.bHeld)
		{
			_moveUp = true;
		}
		else if (moveDown.bHeld)
		{
			_moveDown = true;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			// do nothing
		}
		else if (moveLeft.bHeld)
		{
			_moveLeft = true;
		}
		else if (moveRight.bHeld)
		{
			_moveRight = true;
		}
	}

	void CamObj::OnFixedUpdate()
	{
		if (_moveUp)
		{
			_position.y -= _moveSpeed;
		}

		if (_moveDown)
		{
			_position.y += _moveSpeed;
		}

		if (_moveLeft)
		{
			_position.x -= _moveSpeed;
		}

		if (_moveRight)
		{
			_position.x += _moveSpeed;
		}
	}
}