#include "SpriteContainer.h"

#include "GetQuadOnPivot.h"

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

	void SpriteContainer::RenderSprite(RB::Sprites::SpriteType spriteType, float width, float height, olc::vf2d pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool useWorldSpace)
	{
		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = GetLoadedSprite(spriteType);

		std::array<olc::vf2d, 4> points = RB::Sprites::GetQuadOnPivot(pivotType, width, height, pos);

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
