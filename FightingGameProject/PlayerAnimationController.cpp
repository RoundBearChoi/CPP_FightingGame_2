#include "PlayerAnimationController.h"

namespace RB::Render
{
	PlayerAnimationController::PlayerAnimationController()
	{
		SetHash(typeid(*this));
	}

	PlayerAnimationController::~PlayerAnimationController()
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			delete _vecPlayerAnimationObjs[i];
		}
	}

	void PlayerAnimationController::Init()
	{
		//players
		_playerController = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();

		//sprites
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteID::fighter_0_idle);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteID::fighter_0_walk);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteID::fighter_0_jump_up);
		_spriteRenderer.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteID::fighter_0_fall);

		//animations
		_animationLoader.Init();

		AnimationSpecs idleSpecs;
		idleSpecs.mX_TileCount = 9;
		idleSpecs.mY_TileCount = 1;
		idleSpecs.mTotalSprites = 9;
		idleSpecs.mSkipFixedUpdates = 3;
		idleSpecs.mRenderSize = olc::vf2d{ 400.0, 225.0f };
		idleSpecs.mRenderOffset = olc::vf2d{ 0.0f, 0.0f };
		idleSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_idle;
		idleSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_idle);

		AnimationSpecs walkSpecs;
		walkSpecs.mX_TileCount = 10;
		walkSpecs.mY_TileCount = 1;
		walkSpecs.mTotalSprites = 10;
		walkSpecs.mSkipFixedUpdates = 4;
		walkSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		walkSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		walkSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_walk;
		walkSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_walk);

		AnimationSpecs jumpUpSpecs;
        jumpUpSpecs.mX_TileCount = 3;
		jumpUpSpecs.mY_TileCount = 1;
		jumpUpSpecs.mTotalSprites = 3;
		jumpUpSpecs.mSkipFixedUpdates = 6;
		jumpUpSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		jumpUpSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		jumpUpSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_jump_up;
		jumpUpSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_jump_up);

		AnimationSpecs fallSpecs;
        fallSpecs.mX_TileCount = 3;
		fallSpecs.mY_TileCount = 1;
		fallSpecs.mTotalSprites = 3;
		fallSpecs.mSkipFixedUpdates = 6;
		fallSpecs.mRenderSize = olc::vf2d{ 372.0f, 248.0f };
		fallSpecs.mRenderOffset = olc::vf2d{ 14.0f, 0.0f };
		fallSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_fall;
		fallSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_fall);

		_animationLoader.LoadAnimation(idleSpecs);
		_animationLoader.LoadAnimation(walkSpecs);
		_animationLoader.LoadAnimation(jumpUpSpecs);
		_animationLoader.LoadAnimation(fallSpecs);
	}

	void PlayerAnimationController::OnUpdate()
	{
		SetFirstAnimations();

		RB::Players::iPlayer* p1 = _playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = _playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		SetNewAnimationObjsOnChange(*p1);
		SetNewAnimationObjsOnChange(*p2);

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
		if (_vecPlayerAnimationObjs.size() > 0)
		{
			return;
		}

		RB::Players::iPlayer* p1 = _playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = _playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		RB::Sprites::SpriteID p1_SpriteID = p1->GetSpriteID();
		RB::Sprites::SpriteID p2_SpriteID = p2->GetSpriteID();

		AnimationRenderer* p1_renderer = _animationLoader.GetAnimation(p1_SpriteID);
		AnimationRenderer* p2_renderer = _animationLoader.GetAnimation(p2_SpriteID);

		PlayerAnimationObj* p1_ani_obj = new PlayerAnimationObj(p1, p1_renderer);
		PlayerAnimationObj* p2_ani_obj = new PlayerAnimationObj(p2, p2_renderer);

		_vecPlayerAnimationObjs.push_back(p1_ani_obj);
		_vecPlayerAnimationObjs.push_back(p2_ani_obj);
	}

	void PlayerAnimationController::SetNewAnimationObjsOnChange(RB::Players::iPlayer& player)
	{
		RB::Sprites::SpriteID playerSpriteID = player.GetSpriteID();
		RB::Players::PlayerID playerID = player.GetPlayerID();
		RB::Sprites::SpriteID animationSpriteID = GetSpriteID(playerID);

		if (playerSpriteID != animationSpriteID)
		{
			DeleteAnimationObj(playerID);

			PlayerAnimationObj* playerAnimationObj = new PlayerAnimationObj(&player, _animationLoader.GetAnimation(playerSpriteID));

			_vecPlayerAnimationObjs.push_back(playerAnimationObj);
		}
	}

	RB::Sprites::SpriteID PlayerAnimationController::GetSpriteID(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			if (_vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteID spriteID = _vecPlayerAnimationObjs[i]->GetAnimationSpecs().mSpriteID;

				return spriteID;
			}
		}

		return RB::Sprites::SpriteID::NONE;
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
}