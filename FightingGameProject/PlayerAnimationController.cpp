#include "PlayerAnimationController.h"

#include "AnimationObj.h"
#include "PlayerState.h"
#include "JGetter.h"
#include "RenderLayerType.h"

#include "iPlayerController.h"

#include <cassert>

namespace RB::Render
{
	void PlayerAnimationController::Init()
	{
		_animationContainer.Init();

		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_crouch.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_crouch_idle.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_hadouken.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_idle.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_jab.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_jump_forward_0.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_jump_forward_1.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_jump_up_0.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_jump_up_1.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_standup.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_strong_kick.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_strong_punch.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_strong_wince.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_walk.aniSpecs"));
		_animationContainer.LoadAnimation(_GetAnimationSpecs("AnimationSpecs/f0_wince.aniSpecs"));
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

	AnimationSpecs PlayerAnimationController::_GetAnimationSpecs(std::string path)
	{
		std::string str = RB::JSON::LoadJSONFile(path);
		json_value_s* root = json_parse(str.c_str(), str.size());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0); //player0 animation specs

		json_object_element_s* se = RB::JSON::GetElementInsideElement(*rootElement); //sprite type enum in string
		std::string strEnum = RB::JSON::GetString_FromElement(*se);

		json_object_element_s* e0 = se->next; //mX_TileCount
		int xTileCount = RB::JSON::GetInt_FromElement(*e0);

		json_object_element_s* e1 = e0->next; //mY_TileCount
		int yTileCount = RB::JSON::GetInt_FromElement(*e1);

		json_object_element_s* e2 = e1->next; //mTotalSprites
		int totalSprites = RB::JSON::GetInt_FromElement(*e2);

		json_object_element_s* e3 = e2->next; //mSkipFixedUpdates
		int skipFixedUpdates = RB::JSON::GetInt_FromElement(*e3);

		json_object_element_s* e4 = e3->next;
		float renderScale = RB::JSON::GetFloat_FromElement(*e4);

		json_object_element_s* e5 = e4->next; //mPlayOnce
		int playOnceInt = RB::JSON::GetInt_FromElement(*e5);
		bool playOnce = playOnceInt == 0 ? false : true;

		//load sprites first
		bool loadedSprite = _animationContainer.LoadSprite("PNG files/Aku/" + strEnum + ".png", RB::Sprites::SpriteType::_from_string(strEnum.c_str()));
		
		assert(loadedSprite);

		AnimationSpecs specs;

		specs.mX_TileCount = xTileCount;
		specs.mY_TileCount = yTileCount;
		specs.mTotalSprites = totalSprites;
		specs.mSkipFixedUpdates = skipFixedUpdates;
		specs.mRenderScale = renderScale;
		specs.mPlayOnce = playOnce;
		specs.mSpriteType = RB::Sprites::SpriteType::_from_string(strEnum.c_str());

		free(root);

		return specs;
	}
}
