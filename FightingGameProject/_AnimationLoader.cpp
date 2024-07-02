#include "_AnimationLoader.h"

namespace RB::Render
{
	_AnimationRendererLoader::~_AnimationRendererLoader()
	{
		for (auto i = _animationRenderer.begin(); i != _animationRenderer.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}
	}

	void _AnimationRendererLoader::Init()
	{
		//NONE by default (will render nothing)
		AnimationSpecs none;
		LoadAnimationRenderer(none);
	}

	void _AnimationRendererLoader::LoadAnimationRenderer(AnimationSpecs specs)
	{
		if (specs.mSpriteType._value != RB::Sprites::SpriteType::NONE && specs.mLoadedSprite == nullptr)
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

	AnimationRenderer* _AnimationRendererLoader::GetAnimationRenderer(RB::Sprites::SpriteType spriteType)
	{
		for (auto i = _animationRenderer.begin(); i != _animationRenderer.end(); i++)
		{
			if ((*i)->GetAnimationSpecs().mSpriteType == spriteType)
			{
				return (*i);
			}
		}

		return nullptr;
	}
}
