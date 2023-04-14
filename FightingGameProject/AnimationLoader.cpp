#include "AnimationLoader.h"

namespace RB::Render
{
	AnimationLoader::AnimationLoader()
	{

	}
	AnimationLoader::~AnimationLoader()
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			delete _loadedAnimations[i];
		}
	}

	void AnimationLoader::Init()
	{
		//NONE by default (will render nothing)
		LoadAnimation(0, 0, 0, 0, RB::Sprites::SpriteID::NONE, nullptr);
	}

	void AnimationLoader::LoadAnimation(unsigned int xTileCount, unsigned int yTileCount, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite)
	{
		if (spriteID != RB::Sprites::SpriteID::NONE && loadedSprite == nullptr)
		{
			std::cout << std::endl;
			std::cout << "WARNING: LoadedSprite* is null" << std::endl;
		}
		else
		{
			LoadedAnimation* loaded = new LoadedAnimation(xTileCount, yTileCount, totalSprites, skipFixedUpdates, spriteID, loadedSprite);

			_loadedAnimations.push_back(loaded);
		}
	}

	LoadedAnimation* AnimationLoader::GetAnimation(RB::Sprites::SpriteID spriteID)
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			if (_loadedAnimations[i]->GetSpriteID() == spriteID)
			{
				return _loadedAnimations[i];
			}
		}

		return nullptr;
	}
}