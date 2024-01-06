#include "_SpriteLoader.h"

#include <filesystem>

namespace RB::Sprites
{
	_SpriteLoader::~_SpriteLoader()
	{
		for (auto i = _vecLoadedSprites.begin(); i != _vecLoadedSprites.end(); i++)
		{
			delete (*i);
			*i = nullptr;
		}

		_vecLoadedSprites.clear();
	}

	LoadedSprite* _SpriteLoader::LoadSprite(std::string path, SpriteType spriteEnum)
	{
		std::replace(path.begin(), path.end(), '\\', '/'); //convert directory separators
 
		olc::Sprite* sprite = new olc::Sprite(path);
		olc::Decal* decal = new olc::Decal(sprite);

		LoadedSprite* loadedSprite = new LoadedSprite(path, sprite, decal, spriteEnum);

		_vecLoadedSprites.push_back(loadedSprite);

		return loadedSprite;
	}

	LoadedSprite* _SpriteLoader::GetLoadedSprite(SpriteType spriteEnum)
	{
		for (auto i = _vecLoadedSprites.begin(); i != _vecLoadedSprites.end(); i++)
		{
			if ((*i)->GetSpriteEnum() == spriteEnum)
			{
				return (*i);
			}
		}

		return nullptr;
	}
}