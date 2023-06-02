#include "CamObj.h"

namespace RB::Cam
{
	olc::vi2d CamObj::GetPosition()
	{
		return _camPosition;
	}

	olc::vf2d CamObj::GetRelativePosition(olc::vf2d pos)
	{
		olc::vf2d rel = pos - _camPosition;

		rel *= _zoomAmount;

		return rel;
	}

	float_t CamObj::GetZoom()
	{
		return _zoomAmount;
	}

	void CamObj::Init()
	{

	}

	void CamObj::OnUpdate()
	{
		_getter_inputController.OnUpdate();

		if (_getter_inputController.GetController() == nullptr)
		{
			return;
		}

		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		olc::HWButton zoomIn = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_IN);
		olc::HWButton zoomOut = _getter_inputController.GetController()->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_OUT);

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

		float_t zoomSpeed = 0.75f;

		if (zoomIn.bHeld)
		{
			_zoomAmount += RB::Frames::Time::GetDeltaTime() * zoomSpeed;
		}

		if (zoomOut.bHeld)
		{
			_zoomAmount -= RB::Frames::Time::GetDeltaTime() * zoomSpeed;
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