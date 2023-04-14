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
		unsigned int yTiles = _loadedAnimation->GetYTileCount();
		unsigned int xTiles = _loadedAnimation->GetXTileCount();
		
		_sourceSize.x = (float)_loadedAnimation->GetSpriteSize().x / (float)xTiles;
		_sourceSize.y = (float)_loadedAnimation->GetSpriteSize().y / (float)yTiles;

		_sourcePos.x = (_currentIndex % _loadedAnimation->GetXTileCount()) * _sourceSize.x;
		_sourcePos.y = (int32_t)floor(_currentIndex / _loadedAnimation->GetXTileCount()) * _sourceSize.y;
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
		if (_loadedAnimation->GetSpriteID() == RB::Sprites::SpriteID::NONE)
		{
			return;
		}

		UpdateSourceData();

		_loadedAnimation->RenderAnimation(_currentIndex, _sourcePos, _sourceSize,
			_player->GetPosition(), olc::vf2d{ 300.0f, 150.0f }, //temp sprite size
			RB::Sprites::PivotType::BOTTOM_CENTER);
	}
}