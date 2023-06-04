#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos, float_t percentage)
	{
		_spriteEnum = spriteEnum;
		_position = pos;
		_percentage = percentage;

		_spriteRenderer.LoadSprite(path, spriteEnum);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{

	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}