#pragma once
#include "LoadedAnimation.h"

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

	private:
		LoadedAnimation* _loadedAnimation = nullptr;
	};
}