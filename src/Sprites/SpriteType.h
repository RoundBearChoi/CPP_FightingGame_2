#pragma once

#include "../enum.h"

namespace RB::Sprites
{
	BETTER_ENUM
	(
		SpriteType, int,

		NONE = 0,

		x_white,
		white_sq,
		player_hp_bar_white,

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

		FIGHTER_0_SPRITES_START,

		fighter_0_idle,
		fighter_0_crouch,
		fighter_0_crouch_idle,
		fighter_0_crouch_punch_weak,
		fighter_0_crouch_weak_wince,
		fighter_0_standup,
		fighter_0_walk,

		fighter_0_jump_up,
		fighter_0_fall,

		fighter_0_jump_forward_0, 	//up
		fighter_0_jump_forward_1, 	//down

		fighter_0_jump_back_0,		//up
		fighter_0_jump_back_1,		//down

		fighter_0_jab,
		fighter_0_strong_punch,
		fighter_0_strong_kick,
		
		fighter_0_weak_wince_mid,
		fighter_0_strong_wince_mid,
		fighter_0_strong_wince_high,
		
		fighter_0_hadouken,

		fighter_0_kneel,
		fighter_0_lie_down,

		FIGHTER_0_SPRITES_END,

		background_1,
		background_2,
		background_3,
		background_4,
		background_5,
		background_6,
		background_7,
		background_8,

		vfx_hiteffect_0,
		vfx_hiteffect_head,
		vfx_hiteffect_body,
		vfx_hiteffect_leg,

		COUNT
	)
}
