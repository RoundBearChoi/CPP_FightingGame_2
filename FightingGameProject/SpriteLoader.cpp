#include "SpriteLoader.h"

#include <filesystem>

namespace RB::Sprites
{
	SpriteLoader::~SpriteLoader()
	{

	}

	LoadedSprite* SpriteLoader::LoadSprite(std::string path, SpriteType spriteType)
	{
		std::replace(path.begin(), path.end(), '\\', '/'); //convert directory separators
 
		olc::Sprite* sprite = new olc::Sprite(path);
		olc::Decal* decal = new olc::Decal(sprite);

		LoadedSprite* loadedSprite = new LoadedSprite(path, sprite, decal, spriteType);

		return loadedSprite;
	}
}
