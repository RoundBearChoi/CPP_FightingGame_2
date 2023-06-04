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
		_spriteRenderer.RenderSprite(_spriteEnum, olc::vf2d{100.0f, 100.0f}, _position, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT);
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}