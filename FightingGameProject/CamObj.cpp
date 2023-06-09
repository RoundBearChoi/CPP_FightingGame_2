#include "CamObj.h"

namespace RB::Cam
{
	olc::vf2d CamObj::GetPosition()
	{
		return _camPosition;
	}

	olc::vf2d CamObj::GetRelativePosition(olc::vf2d pos)
	{
		olc::vf2d rel = (pos * _zoom) - _camPosition;

		return rel;
	}

	float_t CamObj::GetZoom()
	{
		return _zoom;
	}

	void CamObj::Init()
	{

	}

	void CamObj::OnUpdate()
	{
		if (RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return;
		}

		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		olc::HWButton zoomIn = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_IN);
		olc::HWButton zoomOut = RB::Input::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_OUT);

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

		if (zoomIn.bHeld)
		{
			_zoom += RB::Frames::Time::GetDeltaTime() * _zoomSpeed;
		}

		if (zoomOut.bHeld)
		{
			_zoom -= RB::Frames::Time::GetDeltaTime() * _zoomSpeed;
		}

		if (_zoom < 0.01f)
		{
			_zoom = 0.01f;
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