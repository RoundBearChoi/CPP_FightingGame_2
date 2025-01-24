#include "HBoxEditController.h"

#include "../Render/iPlayerDebugController.h"
#include "iHBMenuController.h"

namespace RB::HBox
{
	HBoxEditController::HBoxEditController(RB::HBox::HBoxType boxType)
	{
		_boxType = boxType;
	}

	void HBoxEditController::Init()
	{
		INIT_CONTROLLER
		
		_circleRenderer.Init();
	}

	void HBoxEditController::OnUpdate()
	{
		if (_ControllersExist() == false)
		{
			return;
		}

		_Add_Delete_AABB_OnPress();
		_EditAABB_OnPress(RB::Players::PlayerID::PLAYER_1);
		_SaveHBoxes_OnPress();
		_CycleAnimations_OnPress();

		_RenderCircleOnHBox(RB::Players::PlayerID::PLAYER_1);

		Render::iPlayerDebugController* playerDebugController = GET_PLAYER_DEBUG_CONTROLLER;

		if (playerDebugController != nullptr)
		{
			playerDebugController->RenderPlayerHP(false);
			playerDebugController->RenderInput(false);
		}
	}

	void HBoxEditController::OnFixedUpdate()
	{

	}

	RB::HBox::Loaded_HB_Data* HBoxEditController::GetCurrentData(RB::Players::PlayerID playerID, HBoxType boxType)
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		RB::Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		//can get either targetbox or attackbox
		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == HBoxType::TARGET_BOX)
		{
			if (targetBoxDataController != nullptr)
			{
				data = targetBoxDataController->GetData(spriteType);
			}
		}
		else if (boxType == HBoxType::ATTACK_BOX)
		{
			if (attackBoxDataController != nullptr)
			{
				data = attackBoxDataController->GetData(spriteType);
			}
		}

		return data;
	}

	RB::HBox::AABB_Set* HBoxEditController::GetCurrentHBoxData(RB::Players::PlayerID playerID)
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		RB::Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::Loaded_HB_Data* data = nullptr;
		
		// return existing data
		if (_boxType == HBoxType::TARGET_BOX)
		{
			data = targetBoxDataController->GetData(spriteType);
		}
		else if (_boxType == HBoxType::ATTACK_BOX)
		{
			data = attackBoxDataController->GetData(spriteType);
		}

		// create new when data doesn't exist
		if (data == nullptr)
		{
			if (_boxType == HBoxType::TARGET_BOX)
			{
				data = targetBoxDataController->CreateData(spriteType);
			}
			else if (_boxType == HBoxType::ATTACK_BOX)
			{
				data = attackBoxDataController->CreateData(spriteType);
			}

			return nullptr; // shouldn't reach here..
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(currentIndex);

		return AABBs;
	}

	RB::HBox::HBoxType HBoxEditController::GetHBoxType()
	{
		return _boxType;
	}

	bool HBoxEditController::_ControllersExist()
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;
		auto camController = GET_CAM_CONTROLLER;
		auto playerController = GET_PLAYER_CONTROLLER;
		auto playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;
		auto hbMenuController = GET_HB_MENU_CONTROLLER;

		if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (targetBoxDataController == nullptr)
			{
				return false;
			}
		}
		else if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (attackBoxDataController == nullptr)
			{
				return false;
			}
		}

		if (playerController == nullptr ||
			playerAnimationController == nullptr ||
			hbMenuController == nullptr ||
			camController == nullptr)
		{
			return false;
		}

		return true;
	}

	void HBoxEditController::_RenderCircleOnHBox(RB::Players::PlayerID playerID)
	{
		RB::HBox::AABB_Set* AABBs = GetCurrentHBoxData(playerID);

		if (AABBs == nullptr)
		{
			return;
		}

		if (AABBs->GetSelector()->IsEmpty())
		{
			return;
		}

		RB::Collisions::AABB* box = AABBs->GetSelector()->GetSelected();

		if (box == nullptr)
		{
			return;
		}

		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Vector2 pos = player->GetPosition() + box->GetBottomLeft();
		_circleRenderer.SetPos(pos);
		_circleRenderer.Render(2);
		_circleRenderer.Render(3);
	}

	void HBoxEditController::_Add_Delete_AABB_OnPress()
	{
		RB::HBox::AABB_Set* AABBs = GetCurrentHBoxData(RB::Players::PlayerID::PLAYER_1);
		
		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);
		
		if (insButton.bPressed)
		{
			if (AABBs != nullptr)
			{
				AABBs->GetSelector()->PushBack(RB::Collisions::AABB{ 0.0f, 0.0f, 30.0f, 30.0f });

				AABBs->GetSelector()->SelectDown();
			}
			else
			{

			}
		}
		
		if (delButton.bPressed && AABBs != nullptr)
		{
			AABBs->GetSelector()->EraseSelected();
		}
	}

	void HBoxEditController::_EditAABB_OnPress(RB::Players::PlayerID playerID)
	{
		RB::HBox::AABB_Set* AABBs = GetCurrentHBoxData(playerID);

		if (AABBs == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* box = AABBs->GetSelector()->GetSelected();

		if (box == nullptr)
		{
			return;
		}

		olc::HWButton wButton = olc::Platform::ptrPGE->GetKey(olc::W);
		olc::HWButton sButton = olc::Platform::ptrPGE->GetKey(olc::S);

		olc::HWButton aButton = olc::Platform::ptrPGE->GetKey(olc::A);
		olc::HWButton dButton = olc::Platform::ptrPGE->GetKey(olc::D);

		float moveAmount = 50.0f;

		if (wButton.bHeld)
		{
			box->MoveY(-moveAmount * RB::Time::GetDeltaTime());
		}

		if (sButton.bHeld)
		{
			box->MoveY(moveAmount * RB::Time::GetDeltaTime());
		}

		if (aButton.bHeld)
		{
			box->MoveX(-moveAmount * RB::Time::GetDeltaTime());
		}

		if (dButton.bHeld)
		{
			box->MoveX(moveAmount * RB::Time::GetDeltaTime());
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			box->IncreaseHeight(sizeAmount * RB::Time::GetDeltaTime());
		}

		if (jButton.bHeld)
		{
			box->IncreaseHeight(-sizeAmount * RB::Time::GetDeltaTime());
		}

		if (hButton.bHeld)
		{
			box->IncreaseWidth(-sizeAmount * RB::Time::GetDeltaTime());
		}

		if (kButton.bHeld)
		{
			box->IncreaseWidth(sizeAmount * RB::Time::GetDeltaTime());
		}
	}

	void HBoxEditController::_SaveHBoxes_OnPress()
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;
		auto hbMenuController = GET_HB_MENU_CONTROLLER;

		RB::HBox::Loaded_HB_Data* data = GetCurrentData(RB::Players::PlayerID::PLAYER_1, _boxType);

		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hbox set" << std::endl;

			std::string path;

			if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
			{
				path = targetBoxDataController->GetPath(data->GetSpriteType());
			}
			else if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
			{
				path = attackBoxDataController->GetPath(data->GetSpriteType());
			}

			std::ofstream file(path);

			if (file.is_open())
			{
				//start of whole obj
				file << "{" << std::endl;

				const auto& vec_AABB_Sets = data->Get_AABB_Sets();

				for (auto i = vec_AABB_Sets.begin(); i != vec_AABB_Sets.end(); ++i)
				{
					AABB_Set* AABBs = (AABB_Set*)&*i;
					const std::string& frameName = AABBs->GetFrameName();

					file << "    \"" << frameName << "\":" << std::endl;
					file << "    [" << std::endl;

					const auto& vecAABB = AABBs->GetSelector()->GetVector();

					for (auto i = vecAABB.begin(); i != vecAABB.end(); ++i)
					{
						RB::Collisions::AABB aabb = *i;

						file << "        {" << std::endl;
						file << "        \"posX\" : " << aabb.GetBottomLeft().x << "," << std::endl;
						file << "        \"posY\" : " << aabb.GetBottomLeft().y << "," << std::endl;
						file << "        \"width\" : " << aabb.GetWidthHeight().x << "," << std::endl;
						file << "        \"height\" : " << aabb.GetWidthHeight().y << std::endl;

						if (i != AABBs->GetSelector()->GetVector().end() - 1)
						{
							file << "        }," << std::endl;
						}
						else
						{
							file << "        }" << std::endl;
						}
					}

					//no comma for last frame
					if (i != vec_AABB_Sets.end() - 1)
					{
						file << "    ]," << std::endl << std::endl;
					}
					else
					{
						file << "    ]" << std::endl;
					}
				}

				//end of whole obj
				file << "}";

				file.flush();
				file.close();
			}

			hbMenuController->ShowNotification();
		}
	}

	void HBoxEditController::_CycleAnimations_OnPress()
	{
		olc::HWButton home = olc::Platform::ptrPGE->GetKey(olc::HOME);
		olc::HWButton end = olc::Platform::ptrPGE->GetKey(olc::END);

		bool upCycle = false;
		bool downCycle = false;

		if (home.bPressed)
		{
			upCycle = true;
		}

		if (end.bPressed)
		{
			downCycle = true;
		}

		RB::Sprites::SpriteType currentSpriteType = RB::Sprites::SpriteType::NONE;
		RB::Sprites::SpriteType nextSpriteType = RB::Sprites::SpriteType::NONE;

		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (upCycle || downCycle)
		{
			// get current sprite type
			RB::Players::iPlayer* player = playerController->GetPlayerOnIndex(0);
			RB::Players::PlayerState* ownerState = RB::Players::PlayerState::GetPlayerState(player->GetPlayerID());

			currentSpriteType = ownerState->GetSpriteType();
		}

		if (upCycle)
		{
			nextSpriteType._value = currentSpriteType + 1;
		}

		if (downCycle)
		{
			nextSpriteType._value = currentSpriteType - 1;
		}

		if (nextSpriteType._value >= RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END)
		{
			nextSpriteType._value = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1;
		}
		else if (nextSpriteType._value <= RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START)
		{
			nextSpriteType._value = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END - 1;
		}

		if (upCycle || downCycle)
		{
			std::cout << std::endl;
			std::cout << "current sprite: " << currentSpriteType._to_string() << std::endl;
			std::cout << "next sprite: " << nextSpriteType._to_string() << std::endl;

			std::string path = "";

			if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
			{
				path = "../resource/EditorSettings/AttackBoxSettings.editorSettings";
			}
			else if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
			{
				path = "../resource/EditorSettings/TargetBoxSettings.editorSettings";
			}

			std::ofstream file(path);

			if (file.is_open()) {
				file << "{" << std::endl;
				file << "\"AttackBoxEditorSettings\":" << std::endl;
				file << "        {" << std::endl;
				file << "            \"sprite enum\" : \"" << nextSpriteType << "\"," << std::endl;
				file << "            \"other shit\" : \"shit\"" << std::endl;
				file << "        }" << std::endl;
				file << "}" << std::endl;

				file.close();
			}

			// reload updater
			if (upCycle || downCycle)
			{
				if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
				{
					RB::Updaters::ptrCurrentPlayground->QueueAttackBoxEditorUpdater();
				}
				else if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
				{
					RB::Updaters::ptrCurrentPlayground->QueueTargetBoxEditorUpdater();
				}
			}
		}
	}
}