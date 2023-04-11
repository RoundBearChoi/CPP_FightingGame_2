#include "SpriteLoader.h"

namespace RB::Sprites
{
	SpriteLoader::SpriteLoader()
	{

	}

	SpriteLoader::~SpriteLoader()
	{

	}

	void SpriteLoader::LoadSprite(std::string path)
	{
		std::cout << "loading sprite: " << path << std::endl;

		for (const auto& i : std::filesystem::directory_iterator(path))
		{
			std::filesystem::path path = i.path();

			std::cout << "loading sprite (original path): " << path << std::endl;

			std::string p = path.string();
			std::replace(p.begin(), p.end(), '\\', '/'); //convert directory separators

			std::cout << "converted path: " << p << std::endl;

			olc::Sprite* sprite = new olc::Sprite(p);

			//temp
			delete sprite;
		}
	}
}