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
		_animationRenderer.Init();
		_animationRenderer.LoadAnimation(5, 1, 5, RB::Sprites::SpriteID::fighter_0_idle);
	}

	void PlayerAnimationController::OnUpdate()
	{
		//first animations
		if (_vecPlayerAnimationObjs.size() == 0)
		{
			for (int i = 0; i < _vecPlayers.size(); i++)
			{
				RB::Sprites::SpriteID spriteID = _vecPlayers[i]->GetCurrentSpriteID();

				LoadedAnimation* ani = _animationRenderer.GetAnimation(spriteID);

				_vecPlayerAnimationObjs.push_back(new PlayerAnimationObj(_vecPlayers[i], ani));
			}
		}

		//update on change
		for (int i = 0; i < _vecPlayerAnimationObjs.size(); i++)
		{
			RB::Players::PlayerID playerID = _vecPlayerAnimationObjs[i]->GetPlayer()->GetPlayerID();
			RB::Sprites::SpriteID spriteInPlay = GetSpriteID(playerID);
			RB::Sprites::SpriteID spriteID = _vecPlayerAnimationObjs[i]->GetSpriteID();

			if (spriteInPlay != spriteID)
			{

			}
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
				return _vecPlayerAnimationObjs[i]->GetSpriteID();
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