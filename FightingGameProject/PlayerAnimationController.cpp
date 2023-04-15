#include "PlayerAnimationController.h"

namespace RB::Render
{
	PlayerAnimationController::PlayerAnimationController()
	{

	}

	PlayerAnimationController::~PlayerAnimationController()
	{
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			delete _vecPlayerAnimationObjs[i];
		}
	}

	void PlayerAnimationController::Init()
	{
		//players
		RB::Players::iPlayerController* playerController = RB::Controllers::ControllerGroup::FindController<RB::Players::iPlayerController>();

		RB::Players::iPlayer* p1 = playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		_vecPlayers.push_back(p1);
		_vecPlayers.push_back(p2);

		//sprites
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/Fighter_0/fighter_0_idle.png", RB::Sprites::SpriteID::fighter_0_idle);
		_spriteRenderer.LoadSprite("PNG files/Fighter_0/fighter_0_walk.png", RB::Sprites::SpriteID::fighter_0_walk);

		//animations
		_animationLoader.Init();

		AnimationSpecs idleSpecs;
		idleSpecs.mX_TileCount = 5;
		idleSpecs.mY_TileCount = 1;
		idleSpecs.mTotalSprites = 5;
		idleSpecs.mSkipFixedUpdates = 5;
		idleSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_idle;
		idleSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_idle);

		AnimationSpecs walkSpecs;
		walkSpecs.mX_TileCount = 6;
		walkSpecs.mY_TileCount = 1;
		walkSpecs.mTotalSprites = 6;
		walkSpecs.mSkipFixedUpdates = 3;
		walkSpecs.mSpriteID = RB::Sprites::SpriteID::fighter_0_walk;
		walkSpecs.mLoadedSprite = _spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_walk);

		_animationLoader.LoadAnimation(idleSpecs);
		_animationLoader.LoadAnimation(walkSpecs);
	}

	void PlayerAnimationController::OnUpdate()
	{
		SetFirstAnimations();

		SetNewAnimationObjsOnChange();

		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			_vecPlayerAnimationObjs[i]->RenderAnimation();
		}
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			_vecPlayerAnimationObjs[i]->OnFixedUpdate();
		}
	}

	void PlayerAnimationController::SetFirstAnimations()
	{
		if (_vecPlayerAnimationObjs.size() == 0)
		{
			for (int i = 0; i < _vecPlayers.size(); i++)
			{
				RB::Sprites::SpriteID spriteID = _vecPlayers[i]->GetSpriteID();

				AnimationRenderer* animationRenderer = _animationLoader.GetAnimation(spriteID);

				PlayerAnimationObj* playerAnimationObj = new PlayerAnimationObj(_vecPlayers[i], animationRenderer);

				_vecPlayerAnimationObjs.push_back(playerAnimationObj);
			}
		}
	}

	void PlayerAnimationController::SetNewAnimationObjsOnChange()
	{
		for (int i = 0; i < _vecPlayers.size(); i++)
		{
			RB::Sprites::SpriteID playerSpriteID = _vecPlayers[i]->GetSpriteID();
			RB::Players::PlayerID playerID = _vecPlayers[i]->GetPlayerID();
			RB::Sprites::SpriteID animationSpriteID = GetSpriteID(playerID);

			if (playerSpriteID != animationSpriteID)
			{
				std::cout << std::endl;
				std::cout << "player " << (int)playerID << " changed animation to: " << (int)playerSpriteID << std::endl;

				DeleteAnimationObj(playerID);

				PlayerAnimationObj* playerAnimationObj = new PlayerAnimationObj(_vecPlayers[i], _animationLoader.GetAnimation(playerSpriteID));

				_vecPlayerAnimationObjs.push_back(playerAnimationObj);
			}
		}
	}

	RB::Sprites::SpriteID PlayerAnimationController::GetSpriteID(RB::Players::PlayerID playerID)
	{
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
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
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
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