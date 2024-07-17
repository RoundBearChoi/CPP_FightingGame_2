#include "SpriteContainer.h"

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

		if (loaded != nullptr)
		{
			_vecLoadedSprites.push_back(loaded);

			return loaded;
		}
		else
		{
			return nullptr;
		}
	}

	void SpriteContainer::RenderSprite(RB::Sprites::SpriteType spriteType, float width, float height, RB::Vector2 pos, olc::Pixel tint, RB::Sprites::PivotType pivotType, bool isWorldSpace)
	{
		if (RB::Cam::iCamController::Get() == nullptr && isWorldSpace)
		{
			return;
		}

		RB::Sprites::LoadedSprite* loadedSprite = GetLoadedSprite(spriteType);

		std::array<RB::Vector2, 4> points = RB::Sprites::GetQuadOnPivot(pivotType, width, height, pos);

		if (isWorldSpace)
		{
			for (auto i = points.begin(); i != points.end(); i++)
			{
				*i = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(*i);
			}
		}

		std::array<olc::vf2d, 4> arrVF2D;
		
		for (int i = 0; i < points.size(); i++)
		{
			arrVF2D[i] = { points[i].x, points[i].y };
		}

		olc::Decal* decal = loadedSprite->GetDecal();
		olc::Sprite* sprite = loadedSprite->GetSprite();

		olc::vf2d size = { (float)(sprite->Size().x), (float)(sprite->Size().y) };

		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(
			decal,
			arrVF2D,
			{ 0.0f, 0.0f },
			size, //sprite->Size(),
			tint);
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
