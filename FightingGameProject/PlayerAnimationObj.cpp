#include "PlayerAnimationObj.h"

namespace RB::Render
{
	PlayerAnimationObj::PlayerAnimationObj(RB::Players::iPlayer* owner, LoadedAnimation* loadedAnimation)
	{
		_player = owner;
		_loadedAnimation = loadedAnimation;
	}

	PlayerAnimationObj::~PlayerAnimationObj()
	{

	}

	void PlayerAnimationObj::Init()
	{

	}

	void PlayerAnimationObj::OnUpdate()
	{

	}

	void PlayerAnimationObj::OnFixedUpdate()
	{

	}

	RB::Sprites::SpriteID PlayerAnimationObj::GetSpriteID()
	{
		return _loadedAnimation->GetSpriteID();
	}
}