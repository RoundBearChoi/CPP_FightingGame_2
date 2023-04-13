#include "AnimationObj.h"

namespace RB::Render
{
	AnimationObj::AnimationObj(LoadedAnimation* loadedAnimation)
	{
		_loadedAnimation = loadedAnimation;
	}

	AnimationObj::~AnimationObj()
	{

	}

	void AnimationObj::Init()
	{

	}

	void AnimationObj::OnUpdate()
	{

	}

	void AnimationObj::OnFixedUpdate()
	{

	}

	RB::Sprites::SpriteID AnimationObj::GetSpriteID()
	{
		return _loadedAnimation->GetSpriteID();
	}
}