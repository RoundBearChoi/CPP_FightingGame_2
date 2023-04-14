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
		//find players
		RB::Players::iPlayerController* playerController = RB::Controllers::ControllerGroup::FindController<RB::Players::iPlayerController>();

		RB::Players::iPlayer* p1 = playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p2 = playerController->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2);

		_vecPlayers.push_back(p1);
		_vecPlayers.push_back(p2);

		//sprite renderer
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/Fighter_0/fighter_0_idle.png", RB::Sprites::SpriteID::fighter_0_idle);

		//animation renderer
		_animationLoader.Init();
		_animationLoader.LoadAnimation(5, 1, 5, 60,
			RB::Sprites::SpriteID::fighter_0_idle,
			_spriteRenderer.GetLoadedSprite(RB::Sprites::SpriteID::fighter_0_idle));
	}

	void PlayerAnimationController::OnUpdate()
	{
		//first animations
		if (_vecPlayerAnimationObjs.size() == 0)
		{
			for (int i = 0; i < _vecPlayers.size(); i++)
			{
				RB::Sprites::SpriteID spriteID = _vecPlayers[i]->GetSpriteID();

				LoadedAnimation* loadedAnimation = _animationLoader.GetAnimation(spriteID);

				PlayerAnimationObj* playerAnimationObj = new PlayerAnimationObj(_vecPlayers[i], loadedAnimation);

				_vecPlayerAnimationObjs.push_back(playerAnimationObj);
			}
		}

		//update on change
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

	RB::Sprites::SpriteID PlayerAnimationController::GetSpriteID(RB::Players::PlayerID playerID)
	{
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			if (_vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID() == playerID)
			{
				RB::Sprites::SpriteID spriteID = _vecPlayerAnimationObjs[i]->GetSpriteID();

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