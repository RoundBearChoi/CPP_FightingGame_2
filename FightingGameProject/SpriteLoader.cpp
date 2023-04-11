#include "SpriteLoader.h"

namespace RB::Sprites
{
	SpriteLoader::SpriteLoader()
	{

	}

	SpriteLoader::~SpriteLoader()
	{
		for (int i = 0; i < _loadedSprites.size(); i++)
		{
			//std::cout << "destroying sprite: " << _loadedSprites[i]->GetData()->
			delete _loadedSprites[i];
		}
	}

	olc::Sprite* SpriteLoader::LoadSprite(std::string path)
	{
		std::cout << "loading sprite: " << path << std::endl;

		std::replace(path.begin(), path.end(), '\\', '/'); //convert directory separators
 
		olc::Sprite* sprite = new olc::Sprite(path);

		_loadedSprites.push_back(sprite);

		return sprite;
	}
}