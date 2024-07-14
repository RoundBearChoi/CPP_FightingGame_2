#include "PlayerAnimationController.h"

#include <cassert>

#include "AnimationObj.h"
#include "PlayerState.h"
#include "JParser.h"
#include "RenderLayerType.h"

#include "iPlayerController.h"

namespace RB::Render
{
	PlayerAnimationController::~PlayerAnimationController()
	{
		//std::cout << "destructing PlayerAnimationController.." << std::endl;
	}

	void PlayerAnimationController::Init()
	{
		_animationContainer.Init();

		_animationContainer.LoadSprite("PNG files/Aku/fighter_0_idle.png", RB::Sprites::SpriteType::fighter_0_idle);
		_animationContainer.LoadSprite("PNG files/Aku/fighter_0_jab.png", RB::Sprites::SpriteType::fighter_0_jab);
		_animationContainer.LoadSprite("PNG files/Aku/fighter_0_walk.png", RB::Sprites::SpriteType::fighter_0_walk);

		//_animationContainer.LoadAnimation("AnimationSpecs/f0_crouch.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_crouch_idle.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_hadouken.aniSpecs");
		_animationContainer.LoadAnimation("AnimationSpecs/f0_idle.aniSpecs");
		_animationContainer.LoadAnimation("AnimationSpecs/f0_jab.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_jump_forward_0.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_jump_forward_1.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_jump_up_0.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_jump_up_1.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_standup.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_strong_kick.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_strong_punch.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_strong_wince.aniSpecs");
		_animationContainer.LoadAnimation("AnimationSpecs/f0_walk.aniSpecs");
		//_animationContainer.LoadAnimation("AnimationSpecs/f0_wince.aniSpecs");
	}

	void PlayerAnimationController::OnUpdate()
	{
		SetTargetLayer(RenderLayerType::DECALS);

		_SetFirstPlayerAnimations();
		_ChangePlayerAnimations();

		_animationContainer.OnUpdate();
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
		if (RB::Players::iPlayerController::Get() == nullptr)
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
			arr[i] = RB::Players::iPlayerController::Get()->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(arr[i]->GetPlayerID());

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
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::iPlayerController::Get()->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}
	}

	void PlayerAnimationController::_SetNewPlayerAnimationObjOnChange(RB::Players::iPlayer& player)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player.GetPlayerID());

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
