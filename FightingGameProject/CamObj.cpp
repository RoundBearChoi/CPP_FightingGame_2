#include "CamObj.h"

namespace RB::Cam
{
	olc::vi2d CamObj::GetPosition()
	{
		return _camPosition;
	}

	olc::vi2d CamObj::GetRelativePosition(olc::vi2d pos)
	{
		olc::vi2d rel = pos - _camPosition;

		return rel;
	}

	void CamObj::Init()
	{

	}

	void CamObj::OnUpdate()
	{
		if (_inputController == nullptr)
		{
			_inputController = RB::Controllers::ActiveControllers::GetController<RB::Input::InputController>();

			return;
		}

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
			_camPosition.y -= _moveSpeed;
		}

		if (_moveDown)
		{
			_camPosition.y += _moveSpeed;
		}

		if (_moveLeft)
		{
			_camPosition.x -= _moveSpeed;
		}

		if (_moveRight)
		{
			_camPosition.x += _moveSpeed;
		}
	}
}