#include "PlayerAnimationController.h"

#include "RenderLayerType.h"

#include "../Logger/iLogController.h"

namespace RB::Render
{
	PlayerAnimationController::~PlayerAnimationController()
	{
	
	}

	void PlayerAnimationController::Init()
	{
		_animationContainer.Init();

		auto logController = GET_LOG_CONTROLLER;	

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_SPRITE, "loading fighter 0 sprites");  

		for (int i = Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_START + 1; i < Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_END; i++)
		{
			Sprites::SPRITE_TYPE spriteType = Sprites::SPRITE_TYPE::_from_index(i);
			std::string str = spriteType._to_string();
			std::string path = "../resource/PNG files/Aku/" + str + ".png";
			_animationContainer.LoadSprite(path, spriteType);
		}

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_JSON, "loading fighter 0 aniSpecs");  

		for (int i = Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_START + 1; i < Sprites::SPRITE_TYPE::FIGHTER_0_SPRITES_END; i++)
		{
			Sprites::SPRITE_TYPE spriteType = Sprites::SPRITE_TYPE::_from_index(i);
			std::string str = spriteType._to_string();
			std::string path = "../resource/AnimationSpecs/" + str + ".aniSpecs";
			_animationContainer.LoadAnimation(path);
		}
	}

	void PlayerAnimationController::OnUpdate()
	{
		SetTargetLayer(RenderLayerType::DECALS);

		_SetFirstPlayerAnimations();
		_ChangePlayerAnimations();

		_animationContainer.OnUpdate();

		ClearTargetLayer();
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		_animationContainer.OnFixedUpdate();
	}

	void PlayerAnimationController::DeleteAnimationObj(Players::PLAYER_TYPE playerID)
	{
		_animationContainer.DeleteAnimationObjs(playerID);
	}

	iAnimationObj* PlayerAnimationController::GetCurrentAnimationObj(Players::PLAYER_TYPE playerID, Sprites::SPRITE_TYPE spriteType)
	{
		return _animationContainer.GetCurrentAnimationObj(playerID, spriteType);
	}

	void PlayerAnimationController::_SetFirstPlayerAnimations()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		if (_animationContainer.GetVecCurrentAnimations().size() > 0)
		{
			return;
		}

		Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 1; i <= 2; i++)
		{
			arr[i] = playerController->GetPlayer(Players::PLAYER_TYPE::_from_integral(i));

			if (arr[i] == nullptr)
			{
				continue;
			}

			Players::PlayerState* state = Players::PlayerState::GetPlayerState(arr[i]->GetPLAYER_TYPE());

			if (state == nullptr)
			{
				continue;
			}

			Sprites::SPRITE_TYPE spriteType = state->GetSpriteType();

			AnimationRenderer* aniRenderer = _animationContainer.GetAnimationRenderer(spriteType);

			iAnimationObj* animationObj = new AnimationObj(arr[i], aniRenderer, Sprites::PivotType::BOTTOM_CENTER);

			_animationContainer.AddNewAnimation(animationObj);
		}
	}

	void PlayerAnimationController::_ChangePlayerAnimations()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 1; i <= 2; i++)
		{
			arr[i] = playerController->GetPlayer(Players::PLAYER_TYPE::_from_integral(i));

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}
	}

	void PlayerAnimationController::_SetNewPlayerAnimationObjOnChange(Players::iPlayer& player)
	{
		Players::PlayerState* state = Players::PlayerState::GetPlayerState(player.GetPLAYER_TYPE());

		if (state == nullptr)
		{
			return;
		}

		Sprites::SPRITE_TYPE playerSpriteType = state->GetSpriteType();
		Players::PLAYER_TYPE playerID = player.GetPLAYER_TYPE();
		Sprites::SPRITE_TYPE animationSpriteType = _GetPlayerSpriteType(playerID);

		if (playerSpriteType != animationSpriteType)
		{
			DeleteAnimationObj(playerID);

			iAnimationObj* aniObj = _animationContainer.InstantiateNewAnimationObj(player, playerSpriteType, Sprites::PivotType::BOTTOM_CENTER);

			_animationContainer.AddNewAnimation(aniObj);
		}
	}

	Sprites::SPRITE_TYPE PlayerAnimationController::_GetPlayerSpriteType(Players::PLAYER_TYPE playerID)
	{
		return _animationContainer.GetSpriteType(playerID);
	}
}
