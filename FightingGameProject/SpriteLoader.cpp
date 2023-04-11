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

		LoadedSprite* loadedSprite = new LoadedSprite(path, sprite, spriteID);

		_vecLoadedSprites.push_back(loadedSprite);

		return loadedSprite;
	}
}