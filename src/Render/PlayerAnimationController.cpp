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

		logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_SPRITE, "loading fighter 0 sprites");  

		for (int i = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1; i < RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END; i++)
		{
			RB::Sprites::SpriteType spriteType = RB::Sprites::SpriteType::_from_index(i);
			std::string str = spriteType._to_string();
			std::string path = "../resource/PNG files/Aku/" + str + ".png";
			_animationContainer.LoadSprite(path, spriteType);
		}

		logController->AddToStream(Players::PlayerID::NONE, Log::LOG_TYPE::LOAD_JSON, "loading fighter 0 aniSpecs");  

		for (int i = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1; i < RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END; i++)
		{
			RB::Sprites::SpriteType spriteType = RB::Sprites::SpriteType::_from_index(i);
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

	void PlayerAnimationController::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		_animationContainer.DeleteAnimationObjs(playerID);
	}

	iAnimationObj* PlayerAnimationController::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType)
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

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 1; i <= 2; i++)
		{
			arr[i] = playerController->GetPlayer(Players::PlayerID::_from_integral(i));

			if (arr[i] == nullptr)
			{
				continue;
			}

			Players::PlayerState* state = Players::PlayerState::GetPlayerState(arr[i]->GetPlayerID());

			if (state == nullptr)
			{
				continue;
			}

			Sprites::SpriteType spriteType = state->GetSpriteType();

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
			arr[i] = playerController->GetPlayer(Players::PlayerID::_from_integral(i));

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}
	}

	void PlayerAnimationController::_SetNewPlayerAnimationObjOnChange(Players::iPlayer& player)
	{
		Players::PlayerState* state = Players::PlayerState::GetPlayerState(player.GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		Sprites::SpriteType playerSpriteType = state->GetSpriteType();
		Players::PlayerID playerID = player.GetPlayerID();
		Sprites::SpriteType animationSpriteType = _GetPlayerSpriteType(playerID);

		if (playerSpriteType != animationSpriteType)
		{
			DeleteAnimationObj(playerID);

			iAnimationObj* aniObj = _animationContainer.InstantiateNewAnimationObj(player, playerSpriteType, Sprites::PivotType::BOTTOM_CENTER);

			_animationContainer.AddNewAnimation(aniObj);
		}
	}

	Sprites::SpriteType PlayerAnimationController::_GetPlayerSpriteType(Players::PlayerID playerID)
	{
		return _animationContainer.GetSpriteType(playerID);
	}
}
