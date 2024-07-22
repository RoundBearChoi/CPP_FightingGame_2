#include "CamObj.h"

namespace RB::Cam
{
	RB::Vector2 CamObj::GetPosition()
	{
		return _camPosition;
	}

	void CamObj::SetPosition(RB::Vector2 pos)
	{
		_camPosition = pos;
	}

	void CamObj::SetXPosition(float x)
	{
		_camPosition.x = x;
	}

	void CamObj::SetYPosition(float y)
	{
		_camPosition.y = y;
	}

	RB::Vector2 CamObj::GetRelativePosition(RB::Vector2 pos)
	{
		RB::Vector2 rel = (pos * _zoom) - _camPosition;

		rel.x += _displayHalfWidth;
		rel.y += _displayHalfHeight;

		return rel;
	}

	float CamObj::GetZoom()
	{
		return _zoom;
	}

	void CamObj::SetZoom(float zoom)
	{
		_zoom = zoom;
	}

	void CamObj::Init()
	{
		_displayHalfWidth = (float)RB::displayWidth * 0.5f;
		_displayHalfHeight = (float)RB::displayHeight * 0.5f;
	}

	void CamObj::ManualUpdate()
	{
		if (RB::Input::iInputController::Get() == nullptr)
		{
			return;
		}

		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		olc::HWButton zoomIn = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_IN);
		olc::HWButton zoomOut = RB::Input::iInputController::Get()->GetKeyBinding(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::CAM_ZOOM_OUT);

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

		if (_zoom < 0.0001f)
		{
			_zoom = 0.0001f;
		}
	}

	void CamObj::ManualFixedUpdate()
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
