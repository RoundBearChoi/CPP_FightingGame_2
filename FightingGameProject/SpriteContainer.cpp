#include "SpriteContainer.h"

#include "iCamController.h"

namespace RB::Sprites
{
	SpriteContainer::~SpriteContainer()
	{
		for (auto i = _vecLoadedSprites.begin(); i != _vecLoadedSprites.end(); i++)
		{
			delete (*i);
			*i = nullptr;
		}

		_vecLoadedSprites.clear();
	}

	LoadedSprite* SpriteContainer::LoadSprite(std::string path, RB::Sprites::SpriteType spriteType)
	{
		LoadedSprite* loaded = _loader.LoadSprite(path, spriteType);

		_vecLoadedSprites.push_back(loaded);

		return loaded;
	}

	void SpriteContainer::RenderSprite(RB::Sprites::SpriteType spriteType, olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool useWorldSpace)
	{
		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = GetLoadedSprite(spriteType);

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

		if (useWorldSpace)
		{
			for (auto i = points.begin(); i != points.end(); i++)
			{
				*i = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(*i);
			}
		}

		olc::Decal* decal = loadedSprite->GetDecal();
		olc::Sprite* sprite = loadedSprite->GetSprite();

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(decal, points, { 0, 0 }, sprite->Size(), tint);
	}

	RB::Sprites::LoadedSprite* SpriteContainer::GetLoadedSprite(RB::Sprites::SpriteType spriteType)
	{
		for (auto i = _vecLoadedSprites.begin(); i != _vecLoadedSprites.end(); i++)
		{
			if ((*i)->GetSpriteType() == spriteType)
			{
				return (*i);
			}
		}

		return nullptr;
	}
}
