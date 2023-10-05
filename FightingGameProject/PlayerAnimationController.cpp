#include "PlayerAnimationController.h"

namespace RB::Render
{
	PlayerAnimationController::PlayerAnimationController()
	{
		SetHash(typeid(*this));

		PLAYER_ANIMATION_CONTROLLER = this;
	}

	PlayerAnimationController::~PlayerAnimationController()
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			delete _vecCurrentAnimations[i];
		}

		PLAYER_ANIMATION_CONTROLLER = nullptr;
	}

	void PlayerAnimationController::Init()
	{
		//sprites
		_spriteObj.Init();
		_spriteObj.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteEnum::fighter_0_idle);
		_spriteObj.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteEnum::fighter_0_walk);
		_spriteObj.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteEnum::fighter_0_jump_up);
		_spriteObj.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteEnum::fighter_0_fall);
		_spriteObj.LoadSprite("PNG files/Aku/aku_weak_jab.png", RB::Sprites::SpriteEnum::fighter_0_jab);
		_spriteObj.LoadSprite("PNG files/Aku/aku_wince.png", RB::Sprites::SpriteEnum::fighter_0_wince);

		//animations
		_animationLoader.Init();

		AnimationSpecs idleSpecs;
		idleSpecs.mX_TileCount = 9;
		idleSpecs.mY_TileCount = 1;
		idleSpecs.mTotalSprites = 9;
		idleSpecs.mSkipFixedUpdates = 3;
		idleSpecs.mRenderSize = olc::vf2d{ 400.0, 225.0f };
		idleSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		idleSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;
		idleSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_idle);

		AnimationSpecs walkSpecs;
		walkSpecs.mX_TileCount = 10;
		walkSpecs.mY_TileCount = 1;
		walkSpecs.mTotalSprites = 10;
		walkSpecs.mSkipFixedUpdates = 4;
		walkSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		walkSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		walkSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;
		walkSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_walk);

		AnimationSpecs jumpUpSpecs;
        jumpUpSpecs.mX_TileCount = 3;
		jumpUpSpecs.mY_TileCount = 1;
		jumpUpSpecs.mTotalSprites = 3;
		jumpUpSpecs.mSkipFixedUpdates = 6;
		jumpUpSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		jumpUpSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		jumpUpSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;
		jumpUpSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_jump_up);

		AnimationSpecs fallSpecs;
        fallSpecs.mX_TileCount = 3;
		fallSpecs.mY_TileCount = 1;
		fallSpecs.mTotalSprites = 3;
		fallSpecs.mSkipFixedUpdates = 6;
		fallSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		fallSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		fallSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_fall;
		fallSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_fall);

		AnimationSpecs jabSpecs;
		jabSpecs.mX_TileCount = 6;
		jabSpecs.mY_TileCount = 1;
		jabSpecs.mTotalSprites = 6;
		jabSpecs.mSkipFixedUpdates = 2;
		jabSpecs.mRenderSize = olc::vf2d{ 240.0f, 160.0f };
		jabSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		jabSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jab;
		jabSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_jab);

		AnimationSpecs winceSpecs;
		winceSpecs.mX_TileCount = 1;
		winceSpecs.mY_TileCount = 1;
		winceSpecs.mTotalSprites = 1;
		winceSpecs.mSkipFixedUpdates = 2;
		winceSpecs.mRenderSize = olc::vf2d{ 71.5f, 132.1f };
		winceSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		winceSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_wince;
		winceSpecs.mLoadedSprite = _spriteObj.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_wince);

		_animationLoader.LoadAnimation(idleSpecs);
		_animationLoader.LoadAnimation(walkSpecs);
		_animationLoader.LoadAnimation(jumpUpSpecs);
		_animationLoader.LoadAnimation(fallSpecs);
		_animationLoader.LoadAnimation(jabSpecs);
		_animationLoader.LoadAnimation(winceSpecs);
	}

	void PlayerAnimationController::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_SetFirstAnimations();

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewAnimationObjsOnChange(*arr[i]);
		}

		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			RB::Players::iPlayer* p = _vecCurrentAnimations[i]->GetPlayer();

			olc::vi2d pos = p->GetPosition();

			_vecCurrentAnimations[i]->RenderAnimation(pos);
		}
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			_vecCurrentAnimations[i]->OnFixedUpdate();
		}
	}

	void PlayerAnimationController::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				delete _vecCurrentAnimations[i];

				_vecCurrentAnimations.erase(_vecCurrentAnimations.begin() + i);

				return;
			}
		}
	}

	iAnimationObj* PlayerAnimationController::GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				if (_vecCurrentAnimations[i]->GetAnimationSpecs().mSpriteEnum == spriteEnum)
				{
					return _vecCurrentAnimations[i];
				}
			}
		}

		return nullptr;
	}

	void PlayerAnimationController::_SetFirstAnimations()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		if (_vecCurrentAnimations.size() > 0)
		{
			return;
		}

		_vecCurrentAnimations.reserve(4);

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(arr[i]->GetPlayerID());

			if (state == nullptr)
			{
				continue;
			}

			RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

			AnimationRenderer* aniRenderer = _animationLoader.GetAnimation(spriteEnum);

			iAnimationObj* animationObj = new AnimationObj(arr[i], aniRenderer);

			_vecCurrentAnimations.push_back(animationObj);
		}
	}

	void PlayerAnimationController::_SetNewAnimationObjsOnChange(RB::Players::iPlayer& player)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(player.GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum playerSpriteEnum = state->GetSpriteEnum();
		RB::Players::PlayerID playerID = player.GetPlayerID();
		RB::Sprites::SpriteEnum animationSpriteEnum = _GetSpriteEnum(playerID);

		if (playerSpriteEnum != animationSpriteEnum)
		{
			DeleteAnimationObj(playerID);

			iAnimationObj* animationObj = new AnimationObj(&player, _animationLoader.GetAnimation(playerSpriteEnum));

			_vecCurrentAnimations.push_back(animationObj);
		}
	}

	RB::Sprites::SpriteEnum PlayerAnimationController::_GetSpriteEnum(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecCurrentAnimations.size(); i++)
		{
			if (_vecCurrentAnimations[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteEnum spriteEnum = _vecCurrentAnimations[i]->GetAnimationSpecs().mSpriteEnum;

				return spriteEnum;
			}
		}

		return RB::Sprites::SpriteEnum::NONE;
	}
}