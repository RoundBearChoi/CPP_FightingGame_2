#include "SpriteLoader.h"

namespace RB::Sprites
{
	SpriteLoader::~SpriteLoader()
	{
		for (size_t i = 0; i < _vecLoadedSprites.size(); i++)
		{
			delete _vecLoadedSprites[i];
		}
	}

	LoadedSprite* SpriteLoader::LoadSprite(std::string path, SpriteEnum spriteEnum)
	{
		std::replace(path.begin(), path.end(), '\\', '/'); //convert directory separators
 
		olc::Sprite* sprite = new olc::Sprite(path);
		olc::Decal* decal = new olc::Decal(sprite);

		LoadedSprite* loadedSprite = new LoadedSprite(path, sprite, decal, spriteEnum);

		_vecLoadedSprites.push_back(loadedSprite);

		return loadedSprite;
	}

	LoadedSprite* SpriteLoader::GetLoadedSprite(SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecLoadedSprites.size(); i++)
		{
			if (_vecLoadedSprites[i]->GetSpriteEnum() == spriteEnum)
			{
				return _vecLoadedSprites[i];
			}
		}

		return nullptr;
	}
}