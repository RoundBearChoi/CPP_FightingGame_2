#include "PlayerAnimationController.h"
#include "RenderLayerType.h"

namespace RB::Render
{
	PlayerAnimationController::~PlayerAnimationController()
	{
		//std::cout << "destructing PlayerAnimationController.." << std::endl;
	}

	void PlayerAnimationController::Init()
	{
		//INIT_CONTROLLER
		
		_animationContainer.Init();

		for (int i = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1; i < RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END; i++)
		{
			RB::Sprites::SpriteType spriteType = RB::Sprites::SpriteType::_from_index(i);
			std::string str = spriteType._to_string();
			std::string path = "../resource/PNG files/Aku/" + str + ".png";
			_animationContainer.LoadSprite(path, spriteType);
		}

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
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		if (_animationContainer.GetVecCurrentAnimations().size() > 0)
		{
			return;
		}

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 0; i < 2; i++)
		{
			arr[i] = playerController->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(arr[i]->GetPlayerID());

			if (state == nullptr)
			{
				continue;
			}

			RB::Sprites::SpriteType spriteType = state->GetSpriteType();

			AnimationRenderer* aniRenderer = _animationContainer.GetAnimationRenderer(spriteType);

			iAnimationObj* animationObj = new AnimationObj(arr[i], aniRenderer, RB::Sprites::PivotType::BOTTOM_CENTER);

			_animationContainer.AddNewAnimation(animationObj);
		}
	}

	void PlayerAnimationController::_ChangePlayerAnimations()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 0; i < 2; i++)
		{
			arr[i] = playerController->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}
	}

	void PlayerAnimationController::_SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player)
	{
		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(player.GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteType playerSpriteType = state->GetSpriteType();
		RB::Players::PlayerID playerID = player.GetPlayerID();
		RB::Sprites::SpriteType animationSpriteType = _GetPlayerSpriteType(playerID);

		if (playerSpriteType != animationSpriteType)
		{
			DeleteAnimationObj(playerID);

			iAnimationObj* aniObj = _animationContainer.InstantiateNewAnimationObj(player, playerSpriteType, RB::Sprites::PivotType::BOTTOM_CENTER);

			_animationContainer.AddNewAnimation(aniObj);
		}
	}

	RB::Sprites::SpriteType PlayerAnimationController::_GetPlayerSpriteType(RB::Players::PlayerID playerID)
	{
		return _animationContainer.GetSpriteType(playerID);
	}

	void PlayerAnimationController::_SaveAnimationSpecs(std::string path, AnimationSpecs specs)
	{
		std::ofstream file(path);

		std::string name = "player0 animation specs";

		if (file.is_open())
		{
			//start
			file << "{" << std::endl;

			//start of parent element
			file << "    \"" << name << "\":" << std::endl;

			file << "        {" << std::endl;
			file << "        \"mX_TileCount\" : " << specs.mX_TileCount << "," << std::endl; //element inside element
			file << "        \"mY_TileCount\" : " << specs.mY_TileCount << "," << std::endl;
			file << "        \"mTotalSprites\" : " << specs.mTotalSprites << "," << std::endl;
			file << "        \"mSkipFixedUpdates\" : " << specs.mSkipFixedUpdates << "," << std::endl;
			file << "        \"mPlayOnce\" : " << (specs.mPlayOnce ? 1 : 0) << std::endl;
			
			//end of parent element
			file << "        }" << std::endl;

			//end
			file << "}";

			file.flush();
			file.close();
		}
	}
}
