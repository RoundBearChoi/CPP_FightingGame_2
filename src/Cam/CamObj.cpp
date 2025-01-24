#include "CamObj.h"

namespace RB::Cam
{
	Vector2 CamObj::GetPosition()
	{
		return _camPosition;
	}

	void CamObj::SetPosition(Vector2 pos)
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

	Vector2 CamObj::GetRelativePosition(Vector2 pos)
	{
		Vector2 rel = (pos * _zoom) - _camPosition;

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
		_displayHalfWidth = (float)displayWidth * 0.5f;
		_displayHalfHeight = (float)displayHeight * 0.5f;
	}

	void CamObj::ManualUpdate()
	{
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (inputController == nullptr)
		{
			return;
		}

		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::MOVE_CAM_RIGHT);

		olc::HWButton zoomIn = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::CAM_ZOOM_IN);
		olc::HWButton zoomOut = inputController->GetKeyBinding(Players::PlayerID::NONE, Input::PlayerInput::CAM_ZOOM_OUT);

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
			_zoom += Time::GetDeltaTime() * _zoomSpeed;
		}

		if (zoomOut.bHeld)
		{
			_zoom -= Time::GetDeltaTime() * _zoomSpeed;
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