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
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			delete _vecPlayerAnimationObjs[i];
		}

		PLAYER_ANIMATION_CONTROLLER = nullptr;
	}

	void PlayerAnimationController::Init()
	{
		//sprites
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteEnum::fighter_0_idle);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteEnum::fighter_0_walk);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteEnum::fighter_0_jump_up);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteEnum::fighter_0_fall);

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
		idleSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_idle);

		AnimationSpecs walkSpecs;
		walkSpecs.mX_TileCount = 10;
		walkSpecs.mY_TileCount = 1;
		walkSpecs.mTotalSprites = 10;
		walkSpecs.mSkipFixedUpdates = 4;
		walkSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		walkSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		walkSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;
		walkSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_walk);

		AnimationSpecs jumpUpSpecs;
        jumpUpSpecs.mX_TileCount = 3;
		jumpUpSpecs.mY_TileCount = 1;
		jumpUpSpecs.mTotalSprites = 3;
		jumpUpSpecs.mSkipFixedUpdates = 6;
		jumpUpSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		jumpUpSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		jumpUpSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;
		jumpUpSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_jump_up);

		AnimationSpecs fallSpecs;
        fallSpecs.mX_TileCount = 3;
		fallSpecs.mY_TileCount = 1;
		fallSpecs.mTotalSprites = 3;
		fallSpecs.mSkipFixedUpdates = 6;
		fallSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		fallSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		fallSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_fall;
		fallSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteEnum::fighter_0_fall);

		_animationLoader.LoadAnimation(idleSpecs);
		_animationLoader.LoadAnimation(walkSpecs);
		_animationLoader.LoadAnimation(jumpUpSpecs);
		_animationLoader.LoadAnimation(fallSpecs);
	}

	void PlayerAnimationController::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		SetFirstAnimations();

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			SetNewAnimationObjsOnChange(*arr[i]);
		}

		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			_vecPlayerAnimationObjs[i]->RenderAnimation();
		}
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			_vecPlayerAnimationObjs[i]->OnFixedUpdate();
		}
	}

	void PlayerAnimationController::SetFirstAnimations()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		if (_vecPlayerAnimationObjs.size() > 0)
		{
			return;
		}

		_vecPlayerAnimationObjs.reserve(4);

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

			PlayerAnimationObj* animationObj = new PlayerAnimationObj(arr[i], aniRenderer);

			_vecPlayerAnimationObjs.push_back(animationObj);
		}
	}

	void PlayerAnimationController::SetNewAnimationObjsOnChange(RB::Players::iPlayer& player)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(player.GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum playerSpriteEnum = state->GetSpriteEnum();
		RB::Players::PlayerID playerID = player.GetPlayerID();
		RB::Sprites::SpriteEnum animationSpriteEnum = GetSpriteEnum(playerID);

		if (playerSpriteEnum != animationSpriteEnum)
		{
			DeleteAnimationObj(playerID);

			PlayerAnimationObj* playerAnimationObj = new PlayerAnimationObj(&player, _animationLoader.GetAnimation(playerSpriteEnum));

			_vecPlayerAnimationObjs.push_back(playerAnimationObj);
		}
	}

	RB::Sprites::SpriteEnum PlayerAnimationController::GetSpriteEnum(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			if (_vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteEnum spriteEnum = _vecPlayerAnimationObjs[i]->GetAnimationSpecs().mSpriteEnum;

				return spriteEnum;
			}
		}

		return RB::Sprites::SpriteEnum::NONE;
	}

	void PlayerAnimationController::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			if (_vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				delete _vecPlayerAnimationObjs[i];

				_vecPlayerAnimationObjs.erase(_vecPlayerAnimationObjs.begin() + i);

				return;
			}
		}
	}

	PlayerAnimationObj* PlayerAnimationController::GetAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			if (_vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				if (_vecPlayerAnimationObjs[i]->GetAnimationSpecs().mSpriteEnum == spriteEnum)
				{
					return _vecPlayerAnimationObjs[i];
				}
			}
		}

		return nullptr;
	}
}