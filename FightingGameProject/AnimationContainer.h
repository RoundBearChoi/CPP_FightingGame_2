#pragma once

#include "iAnimationObj.h"

namespace RB::Render
{
	class AnimationContainer
	{
	public:
		AnimationContainer() = default;
		~AnimationContainer();

		virtual void AddNewAnimation(iAnimationObj* animationObj);
	};
}