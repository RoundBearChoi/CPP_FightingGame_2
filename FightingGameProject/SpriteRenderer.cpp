#include "SpriteRenderer.h"

namespace RB::Render
{
	void SpriteRenderer::Init()
	{
		
	}

	void SpriteRenderer::LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteLoader.LoadSprite(path, spriteEnum);
	}

	void SpriteRenderer::RenderSprite(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType)
	{
		_getter_camController.OnUpdate();

		if (_getter_camController.GetController() == nullptr)
		{
			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = _spriteLoader.GetLoadedSprite(spriteEnum);

		olc::vf2d half = widthHeight * 0.5f;

		std::array<olc::vf2d, 4> points;

		if (pivotType == RB::Sprites::PivotType::CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - half.y },
				olc::vf2d{ pos.x - half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y + half.y },
				olc::vf2d{ pos.x + half.x, pos.y - half.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_CENTER)
		{
			points = {
				olc::vf2d{ pos.x - half.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x - half.x, pos.y },
				olc::vf2d{ pos.x + half.x, pos.y },
				olc::vf2d{ pos.x + half.x, pos.y - widthHeight.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_LEFT)
		{
            points = {
				olc::vf2d{ pos.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x, pos.y },
				olc::vf2d{ pos.x + widthHeight.x, pos.y },
				olc::vf2d{ pos.x + widthHeight.x, pos.y - widthHeight.y },
			};
		}
		else if (pivotType == RB::Sprites::PivotType::BOTTOM_RIGHT)
		{
			points = {
				olc::vf2d{ pos.x - widthHeight.x, pos.y - widthHeight.y },
				olc::vf2d{ pos.x - widthHeight.x, pos.y },
				olc::vf2d{ pos.x, pos.y },
				olc::vf2d{ pos.x, pos.y - widthHeight.y },
			};
		}

		for (size_t i = 0; i < points.size(); i++)
		{
			points[i] = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(points[i]);
		}

		olc::Decal* decal = loadedSprite->GetDecal();
		olc::Sprite* sprite = loadedSprite->GetSprite();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 0, 0 }, sprite->Size(), tint);
	}

	RB::Sprites::LoadedSprite* SpriteRenderer::GetLoadedSprite(RB::Sprites::SpriteEnum spriteEnum)
	{
		return _spriteLoader.GetLoadedSprite(spriteEnum);
	}
}