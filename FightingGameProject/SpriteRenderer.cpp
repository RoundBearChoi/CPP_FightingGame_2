#include "SpriteRenderer.h"

namespace RB::Render
{
	void SpriteRenderer::Init()
	{
		
	}

	void SpriteRenderer::LoadSprite(std::string path, RB::Sprites::SpriteID spriteID)
	{
		_spriteLoader.LoadSprite(path, spriteID);
	}

	void SpriteRenderer::RenderSprite(RB::Sprites::SpriteID spriteID, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType)
	{
		if (_camController == nullptr)
		{
			_camController = RB::Controllers::ActiveControllers::GetController<RB::Cam::CamController>();

			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = _spriteLoader.GetLoadedSprite(spriteID);

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

		for (int i = 0; i < points.size(); i++)
		{
			points[i] = _camController->GetCamObj()->GetRelativePosition(points[i]);
		}

		olc::Decal* decal = loadedSprite->GetDecal();
		olc::Sprite* sprite = loadedSprite->GetSprite();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 0, 0 }, sprite->Size(), tint);
	}

	RB::Sprites::LoadedSprite* SpriteRenderer::GetLoadedSprite(RB::Sprites::SpriteID spriteID)
	{
		return _spriteLoader.GetLoadedSprite(spriteID);
	}
}