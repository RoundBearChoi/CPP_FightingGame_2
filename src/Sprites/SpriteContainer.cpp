#include "SpriteContainer.h"

#include "../Cam/GetRelPos.h"

#include "../Logger/iLogController.h"

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

	LoadedSprite* SpriteContainer::LoadSprite(std::string path, Sprites::SPRITE_TYPE spriteType)
	{
		auto logController = GET_LOG_CONTROLLER;

		std::stringstream ss;

		ss << "path " << path;

		LoadedSprite* loaded = _loader.LoadSprite(path, spriteType);

		if (loaded != nullptr)
		{
			_vecLoadedSprites.push_back(loaded);

			logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_SPRITE, ss.str()); 

			return loaded;
		}
		else
		{
			ss << " .. FAILED!";

			logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_SPRITE, ss.str()); 
			
			return nullptr;
		}
	}

	void SpriteContainer::RenderSprite(Sprites::SPRITE_TYPE spriteType, float width, float height, RB::Vector2 pos, olc::Pixel tint, Sprites::PivotType pivotType, bool isWorldSpace)
	{
		auto camController = GET_CAM_CONTROLLER;

		if (camController == nullptr && isWorldSpace)
		{
			return;
		}

		Sprites::LoadedSprite* loadedSprite = GetLoadedSprite(spriteType);

		std::array<RB::Vector2, 4> points = Sprites::GetQuadOnPivot(pivotType, width, height, pos);

		if (isWorldSpace)
		{
			for (auto i = points.begin(); i != points.end(); i++)
			{
				*i = RB::Cam::GetRelPos(camController->GetCamObj(), *i); //->GetRelativePosition(*i);
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

	Sprites::LoadedSprite* SpriteContainer::GetLoadedSprite(Sprites::SPRITE_TYPE spriteType)
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
