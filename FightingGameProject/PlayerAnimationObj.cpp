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

	void PlayerAnimationObj::OnFixedUpdate()
	{
		IncreaseAnimationIndex();
	}

	void PlayerAnimationObj::IncreaseAnimationIndex()
	{
		_currentIndex++;
	}

	RB::Sprites::SpriteID PlayerAnimationObj::GetSpriteID()
	{
		return _loadedAnimation->GetSpriteID();
	}

	RB::Players::iPlayer* PlayerAnimationObj::GetPlayer()
	{
		return _player;
	}

	void PlayerAnimationObj::RenderAnimation()
	{
		_loadedAnimation->RenderAnimation(_currentIndex, _player->GetPlayerBox(), RB::Sprites::PivotType::BOTTOM_CENTER);
	}
}