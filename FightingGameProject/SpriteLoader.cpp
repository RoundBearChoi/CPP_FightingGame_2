#include "SpriteLoader.h"

namespace RB::Sprites
{
	SpriteLoader::SpriteLoader()
	{

	}

	SpriteLoader::~SpriteLoader()
	{
		for (int i = 0; i < _vecLoadedSprites.size(); i++)
		{
			delete _vecLoadedSprites[i];
		}
	}

	LoadedSprite* SpriteLoader::LoadSprite(std::string path, SpriteID spriteID)
	{
		std::replace(path.begin(), path.end(), '\\', '/'); //convert directory separators
 
		olc::Sprite* sprite = new olc::Sprite(path);
		olc::Decal* decal = new olc::Decal(sprite);

		LoadedSprite* loadedSprite = new LoadedSprite(path, sprite, decal, spriteID);

		_vecLoadedSprites.push_back(loadedSprite);

		return loadedSprite;
	}

	LoadedSprite* SpriteLoader::GetLoadedSprite(SpriteID spriteID)
	{
		for (int i = 0; i < _vecLoadedSprites.size(); i++)
		{
			if (_vecLoadedSprites[i]->GetSpriteID() == spriteID)
			{
				return _vecLoadedSprites[i];
			}
		}

		return nullptr;
	}
}