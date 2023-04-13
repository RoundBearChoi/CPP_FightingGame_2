#include "AnimationRenderer.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer()
	{

	}
	AnimationRenderer::~AnimationRenderer()
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			delete _loadedAnimations[i];
		}
	}

	void AnimationRenderer::Init()
	{
		//NONE by default (will render nothing)
		LoadAnimation(0, 0, 0, 0, RB::Sprites::SpriteID::NONE, nullptr);
	}

	void AnimationRenderer::LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite)
	{
		if (spriteID != RB::Sprites::SpriteID::NONE && loadedSprite == nullptr)
		{
			std::cout << std::endl;
			std::cout << "WARNING: LoadedSprite* is null" << std::endl;
		}
		else
		{
			LoadedAnimation* loaded = new LoadedAnimation(widthIndexes, heightIndexes, totalSprites, skipFixedUpdates, spriteID, loadedSprite);

			_loadedAnimations.push_back(loaded);
		}
	}

	LoadedAnimation* AnimationRenderer::GetAnimation(RB::Sprites::SpriteID spriteID)
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