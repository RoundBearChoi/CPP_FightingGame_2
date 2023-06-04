#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, float_t percentage)
	{
		//temp background position
		_position = olc::vf2d{ -576.0f, 0.0f };

		_spriteEnum = spriteEnum;
		_percentage = percentage;

		_spriteRenderer.LoadSprite(path, spriteEnum);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{
		//temp background size
		_spriteRenderer.RenderSprite(_spriteEnum, olc::vf2d{ 1152.0f, 720.0f }, _position, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT);
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}