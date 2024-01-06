#include "_AnimationLoader.h"

namespace RB::Render
{
	_AnimationLoader::~_AnimationLoader()
	{
		for (auto i = _animationRenderer.begin(); i != _animationRenderer.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}
	}

	void _AnimationLoader::Init()
	{
		//NONE by default (will render nothing)
		AnimationSpecs none;
		LoadAnimation(none);
	}

	void _AnimationLoader::LoadAnimation(AnimationSpecs specs)
	{
		if (specs.mSpriteEnum != RB::Sprites::SpriteType::NONE && specs.mLoadedSprite == nullptr)
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

	AnimationRenderer* _AnimationLoader::GetAnimationRenderer(RB::Sprites::SpriteType spriteEnum)
	{
		for (auto i = _animationRenderer.begin(); i != _animationRenderer.end(); i++)
		{
			if ((*i)->GetAnimationSpecs().mSpriteEnum == spriteEnum)
			{
				return (*i);
			}
		}

		return nullptr;
	}
}