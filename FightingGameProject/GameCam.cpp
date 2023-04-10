#include "GameCam.h"

namespace RB::Cam
{
	GameCam::GameCam()
	{

	}

	GameCam::~GameCam()
	{

	}

	olc::vi2d GameCam::GetPosition()
	{
		return _position;
	}

	void GameCam::Init()
	{

	}

	void GameCam::OnUpdate()
	{
		olc::HWButton moveUp = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		if (moveUp.bHeld && moveDown.bHeld)
		{
			// do nothing
		}
		else if (moveUp.bHeld)
		{
			_position.y -= 1;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}
		else if (moveDown.bHeld)
		{
			_position.y += 1;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			// do nothing
		}
		else if (moveLeft.bHeld)
		{
			_position.x -= 1;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}
		else if (moveRight.bHeld)
		{
			_position.x += 1;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}
	}

	void GameCam::OnFixedUpdate()
	{

	}
}