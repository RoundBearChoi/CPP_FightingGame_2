#pragma once

namespace RB::Sprites
{
	enum class SpriteEnum
	{
		NONE = 0,

		x_white,
		white_sq_tr80,

		input_arrow_up,
		input_arrow_down,
		input_arrow_left,
		input_arrow_right,
		input_weak_punch,
		input_weak_kick,
		input_strong_punch,
		input_strong_kick,

		fighter_0_idle,
		fighter_0_walk,
		fighter_0_jump_up,
		fighter_0_jump_forward_up_0, //up
		fighter_0_jump_forward_up_1, //down
		fighter_0_fall,
		fighter_0_jab,
		fighter_0_wince,

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