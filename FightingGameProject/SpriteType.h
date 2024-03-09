#pragma once

//#include <iostream>
#include "enum.h"

BETTER_ENUM
(
	TESTING_CLASS, int,

	NONE = 0,
	
	x_white,
	white_sq_tr80
)

namespace RB::Sprites
{
	enum class SpriteType
	{
		NONE = 0,

		x_white,
		white_sq_tr80,

		input_arrow_up,
		input_arrow_down,
		input_arrow_left,
		input_arrow_right,

		input_arrow_up_left,
		input_arrow_up_right,
		input_arrow_down_left,
		input_arrow_down_right,

		input_weak_punch,
		input_weak_kick,

		input_strong_punch,
		input_strong_kick,

		aku_idle,
		aku_crouch,
		aku_crouch_idle,
		aku_standup,
		aku_walk,
		aku_jump_up_0,
		aku_jump_up_1,
		aku_jump_forward_up_0, //up
		aku_jump_forward_up_1, //down
		aku_jab,
		aku_wince,
		aku_hadouken,

		background_1,
		background_2,
		background_3,
		background_4,
		background_5,
		background_6,
		background_7,
		background_8,

		vfx_hiteffect_0,

		COUNT,
	};
}