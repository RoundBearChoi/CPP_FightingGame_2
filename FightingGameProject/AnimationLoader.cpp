#include "AnimationLoader.h"

namespace RB::Render
{
	AnimationLoader::~AnimationLoader()
	{
		for (size_t i = 0; i < _animationRenderer.size(); i++)
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
		if (specs.mSpriteEnum != RB::Sprites::SpriteEnum::NONE && specs.mLoadedSprite == nullptr)
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

	AnimationRenderer* AnimationLoader::GetAnimation(RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _animationRenderer.size(); i++)
		{
			if (_animationRenderer[i]->GetAnimationSpecs().mSpriteEnum == spriteEnum)
			{
				return _animationRenderer[i];
			}
		}

		return nullptr;
	}
}