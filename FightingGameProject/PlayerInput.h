#pragma once

namespace RB::Input
{
	enum class PlayerInput
	{
		NONE,

		MOVE_LEFT,
		MOVE_RIGHT,
		JUMP,

		MOVE_CAM_LEFT,
		MOVE_CAM_RIGHT,
		MOVE_CAM_UP,
		MOVE_CAM_DOWN,

		CAM_ZOOM_IN,
		CAM_ZOOM_OUT,

		COUNT,
	};
}