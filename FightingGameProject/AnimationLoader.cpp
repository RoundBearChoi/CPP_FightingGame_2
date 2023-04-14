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
		AnimationSpecs none;
		LoadAnimation(none);
	}

	void AnimationLoader::LoadAnimation(AnimationSpecs specs)
	{
		if (specs.mSpriteID != RB::Sprites::SpriteID::NONE && specs.mLoadedSprite == nullptr)
		{
			std::cout << std::endl;
			std::cout << "WARNING: LoadedSprite* is null" << std::endl;
		}
		else
		{
			LoadedAnimation* loaded = new LoadedAnimation(specs);

			_loadedAnimations.push_back(loaded);
		}
	}

	LoadedAnimation* AnimationLoader::GetAnimation(RB::Sprites::SpriteID spriteID)
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			if (_loadedAnimations[i]->GetAnimationSpecs().mSpriteID == spriteID)
			{
				return _loadedAnimations[i];
			}
		}

		return nullptr;
	}
}