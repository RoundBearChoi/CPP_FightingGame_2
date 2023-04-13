#include "PlayerAnimationObj.h"

namespace RB::Render
{
	PlayerAnimationObj::PlayerAnimationObj(RB::Players::iPlayer* owner, LoadedAnimation* loadedAnimation)
	{
		_player = owner;
		_loadedAnimation = loadedAnimation;

		_skipFixedUpdates.SetSkipFrames(_loadedAnimation->GetFixedUpdateSkipCount());
		_skipFixedUpdates.SetFunction(this, &PlayerAnimationObj::IncreaseAnimationIndex);
	}

	PlayerAnimationObj::~PlayerAnimationObj()
	{

	}

	void PlayerAnimationObj::OnFixedUpdate()
	{
		_skipFixedUpdates.OnFixedUpdate();
	}

	void PlayerAnimationObj::IncreaseAnimationIndex()
	{
		//std::cout << "increasing animation index for player " << (int)_player->GetPlayerID() << std::endl;

		unsigned int totalSprites = _loadedAnimation->GetTotalSprites();

		_currentIndex++;

		if (_currentIndex >= totalSprites)
		{
			_currentIndex = 0;
		}
	}

	void PlayerAnimationObj::UpdateSourceData()
	{
		_loadedAnimation->GetHeightIndexes();
		_loadedAnimation->GetWidthIndexes();
		
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
		UpdateSourceData();

		_loadedAnimation->RenderAnimation(_currentIndex, _player->GetPlayerBox(), RB::Sprites::PivotType::BOTTOM_CENTER);
	}
}