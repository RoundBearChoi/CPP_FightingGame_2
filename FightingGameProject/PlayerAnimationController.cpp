#include "PlayerAnimationController.h"

#include "AnimationObj.h"
#include "PlayerState.h"
#include "JGetter.h"

#include "iPlayerController.h"

namespace RB::Render
{
	void PlayerAnimationController::Init()
	{
		_animationLoader.Init();

		//animations require loaded sprites first
		//_animationLoader.LoadSprite("PNG files/StickFigures/test_fight_pose_2.png", RB::Sprites::SpriteType::aku_idle);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_crouch.png", RB::Sprites::SpriteType::aku_crouch);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_crouch_idle.png", RB::Sprites::SpriteType::aku_crouch_idle);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_standup.png", RB::Sprites::SpriteType::aku_standup);
		//_animationLoader.LoadSprite("PNG files/FreeKnight_v1/_Run.png", RB::Sprites::SpriteType::aku_walk);
		//_animationLoader.LoadSprite("PNG files/FreeKnight_v1/_Jump.png", RB::Sprites::SpriteType::aku_jump_up_0);
		//_animationLoader.LoadSprite("PNG files/FreeKnight_v1/_Fall.png", RB::Sprites::SpriteType::aku_jump_up_1);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_jump_forward_up_0.png", RB::Sprites::SpriteType::aku_jump_forward_up_0);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_jump_forward_up_1.png", RB::Sprites::SpriteType::aku_jump_forward_up_1);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_jab.png", RB::Sprites::SpriteType::aku_jab);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_wince.png", RB::Sprites::SpriteType::aku_wince);
		//_animationLoader.LoadSprite("PNG files/Aku/aku_hadouken.png", RB::Sprites::SpriteType::aku_hadouken);

		//load specs from json files
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_idle.aniSpecs"), RB::Sprites::SpriteType::aku_idle);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_crouch.aniSpecs"), RB::Sprites::SpriteType::aku_crouch);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_crouch_idle.aniSpecs"), RB::Sprites::SpriteType::aku_crouch_idle);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_standup.aniSpecs"), RB::Sprites::SpriteType::aku_standup);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_walk.aniSpecs"), RB::Sprites::SpriteType::aku_walk);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_up_0.aniSpecs"), RB::Sprites::SpriteType::aku_jump_up_0);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_up_1.aniSpecs"), RB::Sprites::SpriteType::aku_jump_up_1);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_forward_up_0.aniSpecs"), RB::Sprites::SpriteType::aku_jump_forward_up_0);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jump_forward_up_1.aniSpecs"), RB::Sprites::SpriteType::aku_jump_forward_up_1);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_jab.aniSpecs"), RB::Sprites::SpriteType::aku_jab);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_wince.aniSpecs"), RB::Sprites::SpriteType::aku_wince);
		_animationLoader.LoadAnimation(_LoadAnimationSpecs("AnimationSpecs/p0_AnimationSpecs_hadouken.aniSpecs"), RB::Sprites::SpriteType::aku_hadouken);
	}

	void PlayerAnimationController::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		_SetFirstPlayerAnimations();

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 0; i < 2; i++)
		{
			arr[i] = RB::Players::iPlayerController::instance->GetPlayerOnIndex(i);

			if (arr[i] == nullptr)
			{
				continue;
			}

			_SetNewPlayerAnimationObjOnChange(*arr[i]);
		}

		_animationLoader.OnUpdate();
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		_animationLoader.OnFixedUpdate();
	}

	void PlayerAnimationController::DeleteAnimationObj(RB::Players::PlayerID playerID)
	{
		_animationLoader.DeleteAnimationObjs(playerID);
	}

	iAnimationObj* PlayerAnimationController::GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType)
	{
		return _animationLoader.GetCurrentAnimationObj(playerID, spriteType);
	}

	void PlayerAnimationController::_SetFirstPlayerAnimations()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		if (_animationLoader.GetVecCurrentAnimations().size() > 0)
		{
			return;
		}

		RB::Players::iPlayer* arr[2] = { nullptr, nullptr };

		for (int i = 0; i < 2; i++)
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

			RB::Sprites::SpriteType spriteType = state->GetSpriteType();

			AnimationRenderer* aniRenderer = _animationLoader.GetAnimationRenderer(spriteType);

			iAnimationObj* animationObj = new AnimationObj(arr[i], aniRenderer, RB::Sprites::PivotType::BOTTOM_CENTER);

			_animationLoader.AddNewAnimation(animationObj);
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

			iAnimationObj* aniObj = _animationLoader.InstantiateNewAnimationObj(player, playerSpriteType, RB::Sprites::PivotType::BOTTOM_CENTER);

			_animationLoader.AddNewAnimation(aniObj);
		}
	}

	RB::Sprites::SpriteType PlayerAnimationController::_GetPlayerSpriteType(RB::Players::PlayerID playerID)
	{
		return _animationLoader.GetSpriteType(playerID);
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
			file << "        \"mRenderSizeX\" : " << specs.mRenderSize.x << "," << std::endl;
			file << "        \"mRenderSizeY\" : " << specs.mRenderSize.y << "," << std::endl;
			file << "        \"mPlayOnce\" : " << (specs.mPlayOnce ? 1 : 0) << std::endl;
			
			//end of parent element
			file << "        }" << std::endl;

			//end
			file << "}";

			file.flush();
			file.close();
		}
	}

	AnimationSpecs PlayerAnimationController::_LoadAnimationSpecs(std::string path)
	{
		std::string str = RB::JSON::LoadJSONFile(path);
		json_value_s* root = json_parse(str.c_str(), str.size());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0); //player0 animation specs

		json_object_element_s* pngPath = RB::JSON::GetElementInsideElement(*rootElement); //png path
		std::string strPath = RB::JSON::GetString_FromElement(*pngPath);

		json_object_element_s* se = pngPath->next; //sprite type enum in string
		std::string strEnum = RB::JSON::GetString_FromElement(*se);

		json_object_element_s* e0 = se->next; //mX_TileCount
		int xTileCount = RB::JSON::GetInt_FromElement(*e0);

		json_object_element_s* e1 = e0->next; //mY_TileCount
		int yTileCount = RB::JSON::GetInt_FromElement(*e1);

		json_object_element_s* e2 = e1->next; //mTotalSprites
		int totalSprites = RB::JSON::GetInt_FromElement(*e2);

		json_object_element_s* e3 = e2->next; //mSkipFixedUpdates
		int skipFixedUpdates = RB::JSON::GetInt_FromElement(*e3);

		json_object_element_s* e4 = e3->next; //mRenderSizeX
		float renderSizeX = RB::JSON::GetFloat_FromElement(*e4);

		json_object_element_s* e5 = e4->next; //mRenderSizeY
		float renderSizeY = RB::JSON::GetFloat_FromElement(*e5);

		json_object_element_s* e6 = e5->next; //mPlayOnce
		int playOnceInt = RB::JSON::GetInt_FromElement(*e6);
		bool playOnce = playOnceInt == 0 ? false : true;

		//load sprites first
		 _animationLoader.LoadSprite(strPath, RB::Sprites::SpriteType::_from_string(strEnum.c_str()));

		//should probably check if loaded sprite is null..

		AnimationSpecs specs;

		specs.mX_TileCount = xTileCount;
		specs.mY_TileCount = yTileCount;
		specs.mTotalSprites = totalSprites;
		specs.mSkipFixedUpdates = skipFixedUpdates;
		specs.mRenderSize = olc::vf2d{ renderSizeX, renderSizeY };
		specs.mPlayOnce = playOnce;

		free(root);

		return specs;
	}
}