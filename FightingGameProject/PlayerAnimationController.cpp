#include "PlayerAnimationController.h"

namespace RB::Render
{
	PlayerAnimationController::PlayerAnimationController()
	{
		PLAYER_ANIMATION_CONTROLLER = this;
	}

	PlayerAnimationController::~PlayerAnimationController()
	{
		PLAYER_ANIMATION_CONTROLLER = nullptr;
	}

	void PlayerAnimationController::Init()
	{
		_ani.Init();

		//sprites
		_ani.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteEnum::fighter_0_idle);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteEnum::fighter_0_walk);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteEnum::fighter_0_jump_up);
		_ani.LoadSprite("PNG files/Aku/aku_jump_forward_up_0.png", RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0);
		_ani.LoadSprite("PNG files/Aku/aku_jump_forward_up_1.png", RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteEnum::fighter_0_fall);
		_ani.LoadSprite("PNG files/Aku/aku_weak_jab.png", RB::Sprites::SpriteEnum::fighter_0_jab);
		_ani.LoadSprite("PNG files/Aku/aku_wince.png", RB::Sprites::SpriteEnum::fighter_0_wince);
		_ani.LoadSprite("PNG files/Aku/aku_hadouken.png", RB::Sprites::SpriteEnum::fighter_0_hadouken);

		//animations (requires loades sprites first)
		AnimationSpecs idleSpecs;
		idleSpecs.mX_TileCount = 9;
		idleSpecs.mY_TileCount = 1;
		idleSpecs.mTotalSprites = 9;
		idleSpecs.mSkipFixedUpdates = 3;
		idleSpecs.mRenderSize = olc::vf2d{ 400.0, 225.0f };
		idleSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		idleSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		_ani.LoadAnimation(idleSpecs, RB::Sprites::SpriteEnum::fighter_0_idle);

		AnimationSpecs walkSpecs;
		walkSpecs.mX_TileCount = 10;
		walkSpecs.mY_TileCount = 1;
		walkSpecs.mTotalSprites = 10;
		walkSpecs.mSkipFixedUpdates = 4;
		walkSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		walkSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		walkSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_walk;

		_ani.LoadAnimation(walkSpecs, RB::Sprites::SpriteEnum::fighter_0_walk);

		AnimationSpecs jumpUpSpecs;
        jumpUpSpecs.mX_TileCount = 3;
		jumpUpSpecs.mY_TileCount = 1;
		jumpUpSpecs.mTotalSprites = 3;
		jumpUpSpecs.mSkipFixedUpdates = 6;
		jumpUpSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		jumpUpSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		jumpUpSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;

		_ani.LoadAnimation(jumpUpSpecs, RB::Sprites::SpriteEnum::fighter_0_jump_up);

		AnimationSpecs jumpForwardUp_0_Specs;
		jumpForwardUp_0_Specs.mX_TileCount = 4;
		jumpForwardUp_0_Specs.mY_TileCount = 1;
		jumpForwardUp_0_Specs.mTotalSprites = 4;
		jumpForwardUp_0_Specs.mSkipFixedUpdates = 5;
		jumpForwardUp_0_Specs.mRenderSize = olc::vf2d{ 167.0f, 133.0f };
		jumpForwardUp_0_Specs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		jumpForwardUp_0_Specs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0;
		jumpForwardUp_0_Specs.mPlayOnce = true;

		_ani.LoadAnimation(jumpForwardUp_0_Specs, RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0);

		AnimationSpecs jumpForwardUp_1_Specs;
		jumpForwardUp_1_Specs.mX_TileCount = 4;
		jumpForwardUp_1_Specs.mY_TileCount = 1;
		jumpForwardUp_1_Specs.mTotalSprites = 4;
		jumpForwardUp_1_Specs.mSkipFixedUpdates = 5;
		jumpForwardUp_1_Specs.mRenderSize = olc::vf2d{ 167.0f, 133.0f };
		jumpForwardUp_1_Specs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		jumpForwardUp_1_Specs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1;
		jumpForwardUp_1_Specs.mPlayOnce = true;

		_ani.LoadAnimation(jumpForwardUp_1_Specs, RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1);

		AnimationSpecs fallSpecs;
        fallSpecs.mX_TileCount = 3;
		fallSpecs.mY_TileCount = 1;
		fallSpecs.mTotalSprites = 3;
		fallSpecs.mSkipFixedUpdates = 6;
		fallSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		fallSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		fallSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_fall;

		_ani.LoadAnimation(fallSpecs, RB::Sprites::SpriteEnum::fighter_0_fall);

		AnimationSpecs jabSpecs;
		jabSpecs.mX_TileCount = 6;
		jabSpecs.mY_TileCount = 1;
		jabSpecs.mTotalSprites = 6;
		jabSpecs.mSkipFixedUpdates = 2;
		jabSpecs.mRenderSize = olc::vf2d{ 280.0f, 160.0f };
		jabSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		jabSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_jab;

		_ani.LoadAnimation(jabSpecs, RB::Sprites::SpriteEnum::fighter_0_jab);

		AnimationSpecs winceSpecs;
		winceSpecs.mX_TileCount = 1;
		winceSpecs.mY_TileCount = 1;
		winceSpecs.mTotalSprites = 1;
		winceSpecs.mSkipFixedUpdates = 2;
		winceSpecs.mRenderSize = olc::vf2d{ 71.5f, 132.1f };
		winceSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		winceSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_wince;

		_ani.LoadAnimation(winceSpecs, RB::Sprites::SpriteEnum::fighter_0_wince);

		AnimationSpecs hadoukenSpecs;
		hadoukenSpecs.mX_TileCount = 13;
		hadoukenSpecs.mY_TileCount = 1;
		hadoukenSpecs.mTotalSprites = 13;
		hadoukenSpecs.mSkipFixedUpdates = 3;
		hadoukenSpecs.mRenderSize = olc::vf2d{ 170.0f, 170.0f };
		hadoukenSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		hadoukenSpecs.mSpriteEnum = RB::Sprites::SpriteEnum::fighter_0_hadouken;
		hadoukenSpecs.mPlayOnce = true;

		_ani.LoadAnimation(hadoukenSpecs, RB::Sprites::SpriteEnum::fighter_0_hadouken);
	}

	void PlayerAnimationController::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		_SetFirstPlayerAnimations();

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}

		_ani.OnUpdate();
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		_ani.OnFixedUpdate();
	}

	void PlayerAnimationController::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		_ani.DeleteAnimationObj(playerID);
	}

	iAnimationObj* PlayerAnimationController::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum)
	{
		return _ani.GetCurrentAnimationObj(playerID, spriteEnum);
	}

	void PlayerAnimationController::_SetFirstPlayerAnimations()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		if (_ani.GetCurrentAniCount() > 0)
		{
			return;
		}

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(arr[i]->GetPlayerID());

			if (state == nullptr)
			{
				continue;
			}

			RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

			AnimationRenderer* aniRenderer = _ani.GetAnimationRenderer(spriteEnum);

			iAnimationObj* animationObj = new AnimationObj(arr[i], aniRenderer, RB::Sprites::PivotType::BOTTOM_CENTER);

			_ani.PushCurrentAnimation(animationObj);
		}
	}

	void PlayerAnimationController::_SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player.GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum playerSpriteEnum = state->GetSpriteEnum();
		RB::Players::PlayerID playerID = player.GetPlayerID();
		RB::Sprites::SpriteEnum animationSpriteEnum = _GetPlayerSpriteEnum(playerID);

		if (playerSpriteEnum != animationSpriteEnum)
		{
			DeleteAnimationObj(playerID);

			iAnimationObj* aniObj = _ani.InstantiateNewAnimationObj(player, playerSpriteEnum, RB::Sprites::PivotType::BOTTOM_CENTER);

			_ani.PushCurrentAnimation(aniObj);
		}
	}

	RB::Sprites::SpriteEnum PlayerAnimationController::_GetPlayerSpriteEnum(RB::Players::PlayerID playerID)
	{
		return _ani.GetSpriteEnum(playerID);
	}
}