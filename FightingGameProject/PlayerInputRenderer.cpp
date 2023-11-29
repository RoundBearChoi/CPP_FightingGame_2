#include "PlayerInputRenderer.h"

namespace RB::Render
{
	void PlayerInputRenderer::Init(Sprites* sprites)
	{
		_sprites = sprites;
	}

	void PlayerInputRenderer::OnUpdate()
	{
		_RenderIcon(RB::Sprites::SpriteEnum::input_arrow_up, olc::vi2d(5, 40), olc::WHITE);
	}

	void PlayerInputRenderer::OnFixedUpdate()
	{

	}

	void PlayerInputRenderer::_RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint)
	{
		_sprites->RenderSprite(spriteEnum, olc::vi2d{ 30, 30 }, pos, tint, RB::Sprites::PivotType::BOTTOM_LEFT, false);
	}
}