#include "StringToSpriteEnum.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteEnum GetEnum(std::string str)
	{
		if (str._Equal("fighter_0_idle")) { return RB::Sprites::SpriteEnum::fighter_0_idle; }
		if (str._Equal("fighter_0_walk")) { return RB::Sprites::SpriteEnum::fighter_0_walk; }
		if (str._Equal("fighter_0_jump_up")) { return RB::Sprites::SpriteEnum::fighter_0_jump_up; }
		if (str._Equal("fighter_0_jump_forward_up_0")) { return RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0; }
		if (str._Equal("fighter_0_jump_forward_up_1")) { return RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1; }
		if (str._Equal("fighter_0_fall")) { return RB::Sprites::SpriteEnum::fighter_0_fall; }
		if (str._Equal("fighter_0_jab")) { return RB::Sprites::SpriteEnum::fighter_0_jab; }
		if (str._Equal("fighter_0_wince")) { return RB::Sprites::SpriteEnum::fighter_0_wince; }
		if (str._Equal("fighter_0_hadouken")) { return RB::Sprites::SpriteEnum::fighter_0_hadouken; }

		return RB::Sprites::SpriteEnum::NONE;
	}

	std::string GetString(RB::Sprites::SpriteEnum spriteEnum)
	{
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_idle) { return "\"fighter_0_idle\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_walk) { return "\"fighter_0_walk\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_jump_up) { return "\"fighter_0_jump_up\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0) { return "\"fighter_0_jump_forward_up_0\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1) { return "\"fighter_0_jump_forward_up_1\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_fall) { return "\"fighter_0_fall\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_jab) { return "\"fighter_0_jab\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_wince) { return "\"fighter_0_wince\""; }
		if (spriteEnum == RB::Sprites::SpriteEnum::fighter_0_hadouken) { return "\"fighter_0_hadouken\""; }

		return "NONE";
	}
}