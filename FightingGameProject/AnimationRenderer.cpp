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
		AnimationSpecs none;
		LoadAnimation(none);
	}

	void AnimationRenderer::LoadAnimation(AnimationSpecs specs)
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

	LoadedAnimation* AnimationRenderer::GetAnimation(RB::Sprites::SpriteID spriteID)
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