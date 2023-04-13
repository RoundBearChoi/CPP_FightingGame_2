#pragma once
#include "LoadedAnimation.h"
#include "SpriteID.h"

namespace RB::Render
{
	class AnimationObj
	{
	public:
		AnimationObj(LoadedAnimation* loadedAnimation);
		~AnimationObj();

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	public:
		RB::Sprites::SpriteID GetSpriteID();

	private:
		LoadedAnimation* _loadedAnimation = nullptr;
	};
}