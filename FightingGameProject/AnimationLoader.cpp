#include "AnimationLoader.h"

namespace RB::Render
{
	AnimationLoader::~AnimationLoader()
	{
		for (int i = 0; i < _animationRenderer.size(); i++)
		{
			delete _animationRenderer[i];
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
			AnimationRenderer* loaded = new AnimationRenderer(specs);

			_animationRenderer.push_back(loaded);
		}
	}

	AnimationRenderer* AnimationLoader::GetAnimation(RB::Sprites::SpriteID spriteID)
	{
		for (int i = 0; i < _animationRenderer.size(); i++)
		{
			if (_animationRenderer[i]->GetAnimationSpecs().mSpriteID == spriteID)
			{
				return _animationRenderer[i];
			}
		}

		return nullptr;
	}
}