#pragma once

#include "enum.h"

namespace RB::Sprites
{
	BETTER_ENUM
	(
		SpriteType, int,

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

		FIGHTER_SPRITES_START,

		fighter_0_idle,
		fighter_0_crouch,
		fighter_0_crouch_idle,
		aku_standup,
		aku_walk,
		aku_jump_up_0,
		aku_jump_up_1,
		aku_jump_forward_up_0, //up
		aku_jump_forward_up_1, //down
		aku_jab,
		aku_strong_punch,
		aku_strong_kick,
		aku_wince,
		aku_strong_wince,
		aku_hadouken,

		FIGHTER_SPRITES_END,

		background_1,
		background_2,
		background_3,
		background_4,
		background_5,
		background_6,
		background_7,
		background_8,

		vfx_hiteffect_0,

		COUNT
	)
}
