#include "PlayerAnimationController.h"

namespace RB::Render
{
	void PlayerAnimationController::Init()
	{
		_ani.Init();

		//animations require loaded sprites first
		_ani.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteEnum::fighter_0_idle);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteEnum::fighter_0_walk);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteEnum::fighter_0_jump_up);
		_ani.LoadSprite("PNG files/Aku/aku_jump_forward_up_0.png", RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0);
		_ani.LoadSprite("PNG files/Aku/aku_jump_forward_up_1.png", RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1);
		_ani.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteEnum::fighter_0_fall);
		_ani.LoadSprite("PNG files/Aku/aku_weak_jab.png", RB::Sprites::SpriteEnum::fighter_0_jab);
		_ani.LoadSprite("PNG files/Aku/aku_wince.png", RB::Sprites::SpriteEnum::fighter_0_wince);
		_ani.LoadSprite("PNG files/Aku/aku_hadouken.png", RB::Sprites::SpriteEnum::fighter_0_hadouken);

		//load specs from json files
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_idle.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_idle);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_walk.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_walk);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_up.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_jump_up);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_forward_up_0.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_forward_up_1.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_fall.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_fall);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jab.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_jab);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_wince.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_wince);
		_ani.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_hadouken.aniSpecs"), RB::Sprites::SpriteEnum::fighter_0_hadouken);
	}

	void PlayerAnimationController::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		_SetFirstPlayerAnimations();

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (size_t i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::iPlayerController::instance->GetPlayerOnIndex(i);

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
		if (RB::Players::iPlayerController::instance == nullptr)
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
			arr[i] = RB::Players::iPlayerController::instance->GetPlayerOnIndex(i);

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

	void PlayerAnimationController::_SaveAnimationSpecs(std::string path, AnimationSpecs specs)
	{
		std::ofstream file(path);

		std::string name = "player0 animation specs";

		if (file.is_open())
		{
			//start of whole obj
			file << "{" << std::endl;

			//start of element(?)
			file << "    \"" << name << "\":" << std::endl;

			file << "        {" << std::endl;
			file << "        \"mX_TileCount\" : " << specs.mX_TileCount << "," << std::endl;
			file << "        \"mY_TileCount\" : " << specs.mY_TileCount << "," << std::endl;
			file << "        \"mTotalSprites\" : " << specs.mTotalSprites << "," << std::endl;
			file << "        \"mSkipFixedUpdates\" : " << specs.mSkipFixedUpdates << "," << std::endl;
			file << "        \"mRenderSizeX\" : " << specs.mRenderSize.x << "," << std::endl;
			file << "        \"mRenderSizeY\" : " << specs.mRenderSize.y << "," << std::endl;
			file << "        \"mSpriteEnum\" : " << RB::Sprites::GetString(specs.mSpriteEnum) << "," << std::endl;
			file << "        \"mPlayOnce\" : " << (specs.mPlayOnce ? 1 : 0) << std::endl;
			
			//end of element(?)
			file << "        }" << std::endl;

			//end of whole obj
			file << "}";

			file.flush();
			file.close();
		}
	}

	AnimationSpecs PlayerAnimationController::_LoadAnimationSpecs(std::string path)
	{
		std::string str = RB::JSON::LoadJSONFile(path);

		const char* arrChar = str.c_str();

		struct json_value_s* jRoot = json_parse(arrChar, strlen(arrChar));
		struct json_object_s* jObj = json_value_as_object(jRoot);

		struct json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0); //player0 animation specs

		struct json_object_element_s* e0 = RB::JSON::GetElementInsideElement(*rootElement); //mX_TileCount
		int32_t xTileCount = RB::JSON::GetInt32_FromElement(*e0);

		struct json_object_element_s* e1 = e0->next; //mY_TileCount
		int32_t yTileCount = RB::JSON::GetInt32_FromElement(*e1);

		struct json_object_element_s* e2 = e1->next; //mTotalSprites
		int32_t totalSprites = RB::JSON::GetInt32_FromElement(*e2);

		struct json_object_element_s* e3 = e2->next; //mSkipFixedUpdates
		int32_t skipFixedUpdates = RB::JSON::GetInt32_FromElement(*e3);

		struct json_object_element_s* e4 = e3->next; //mRenderSizeX
		float_t renderSizeX = RB::JSON::GetFloat_FromElement(*e4);

		struct json_object_element_s* e5 = e4->next; //mRenderSizeY
		float_t renderSizeY = RB::JSON::GetFloat_FromElement(*e5);

		struct json_object_element_s* e6 = e5->next; //mSpriteEnum
		std::string spriteEnumStr = RB::JSON::GetString_FromElement(*e6);
		RB::Sprites::SpriteEnum spriteEnum = RB::Sprites::GetEnum(spriteEnumStr);

		struct json_object_element_s* e7 = e6->next; //mPlayOnce
		int32_t playOnceInt = RB::JSON::GetInt32_FromElement(*e7);
		bool playOnce = playOnceInt == 0 ? false : true;

		AnimationSpecs specs;

		specs.mX_TileCount = xTileCount;
		specs.mY_TileCount = yTileCount;
		specs.mTotalSprites = totalSprites;
		specs.mSkipFixedUpdates = skipFixedUpdates;
		specs.mRenderSize = olc::vf2d{ renderSizeX, renderSizeY };
		specs.mSpriteEnum = spriteEnum;
		specs.mPlayOnce = playOnce;

		return specs;
	}
}