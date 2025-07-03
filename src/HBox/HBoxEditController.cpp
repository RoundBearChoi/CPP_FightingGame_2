#include "HBoxEditController.h"

#include "../Render/iPlayerDebugController.h"
#include "iHBMenuController.h"

namespace RB::HBox
{
	HBoxEditController::HBoxEditController(HBox::HBoxType boxType)
	{
		_boxType = boxType;
	}

	void HBoxEditController::Init()
	{
		//INIT_CONTROLLER
		
		_circleRenderer.Init();
	}

	void HBoxEditController::OnUpdate()
	{
		if (_ControllersExist() == false)
		{
			return;
		}

		_Add_Delete_AABB_OnPress();
		_EditAABB_OnPress(Players::PlayerID::PLAYER_1);
		_SaveHBoxes_OnPress();
		_CycleAnimations_OnPress();

		_RenderCircleOnHBox(Players::PlayerID::PLAYER_1);

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

	HBox::Loaded_HB_Data* HBoxEditController::GetCurrentData(Players::PlayerID playerID, HBoxType boxType)
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		Players::PlayerState* state = Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		//can get either targetbox or attackbox
		HBox::Loaded_HB_Data* data = nullptr;

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

	HBox::AABB_Set* HBoxEditController::GetCurrentHBoxData(Players::PlayerID playerID)
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		Players::PlayerState* state = Players::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(playerID, spriteType);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int currentIndex = aniObj->GetCurrentIndex();

		HBox::Loaded_HB_Data* data = nullptr;
		
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

		HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(currentIndex);

		return AABBs;
	}

	HBox::HBoxType HBoxEditController::GetHBoxType()
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

		if (_boxType == HBox::HBoxType::TARGET_BOX)
		{
			if (targetBoxDataController == nullptr)
			{
				return false;
			}
		}
		else if (_boxType == HBox::HBoxType::ATTACK_BOX)
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

	void HBoxEditController::_RenderCircleOnHBox(Players::PlayerID playerID)
	{
		HBox::AABB_Set* AABBs = GetCurrentHBoxData(playerID);

		if (AABBs == nullptr)
		{
			return;
		}

		if (AABBs->GetSelector()->IsEmpty())
		{
			return;
		}

		Collisions::AABB* box = AABBs->GetSelector()->GetSelected();

		if (box == nullptr)
		{
			return;
		}

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(playerID);

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
		HBox::AABB_Set* AABBs = GetCurrentHBoxData(Players::PlayerID::PLAYER_1);
		
		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);
		
		if (insButton.bPressed)
		{
			if (AABBs != nullptr)
			{
				AABBs->GetSelector()->PushBack(Collisions::AABB{ 0.0f, 0.0f, 30.0f, 30.0f });

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

	void HBoxEditController::_EditAABB_OnPress(Players::PlayerID playerID)
	{
		HBox::AABB_Set* AABBs = GetCurrentHBoxData(playerID);

		if (AABBs == nullptr)
		{
			return;
		}

		Collisions::AABB* box = AABBs->GetSelector()->GetSelected();

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
			box->MoveY(-moveAmount * Time::GetDeltaTime());
		}

		if (sButton.bHeld)
		{
			box->MoveY(moveAmount * Time::GetDeltaTime());
		}

		if (aButton.bHeld)
		{
			box->MoveX(-moveAmount * Time::GetDeltaTime());
		}

		if (dButton.bHeld)
		{
			box->MoveX(moveAmount * Time::GetDeltaTime());
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			box->IncreaseHeight(sizeAmount * Time::GetDeltaTime());
		}

		if (jButton.bHeld)
		{
			box->IncreaseHeight(-sizeAmount * Time::GetDeltaTime());
		}

		if (hButton.bHeld)
		{
			box->IncreaseWidth(-sizeAmount * Time::GetDeltaTime());
		}

		if (kButton.bHeld)
		{
			box->IncreaseWidth(sizeAmount * Time::GetDeltaTime());
		}
	}

	void HBoxEditController::_SaveHBoxes_OnPress()
	{
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;
		auto hbMenuController = GET_HB_MENU_CONTROLLER;

		HBox::Loaded_HB_Data* data = GetCurrentData(Players::PlayerID::PLAYER_1, _boxType);

		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hbox set" << std::endl;

			std::string path;

			if (_boxType == HBox::HBoxType::TARGET_BOX)
			{
				path = targetBoxDataController->GetPath(data->GetSpriteType());
			}
			else if (_boxType == HBox::HBoxType::ATTACK_BOX)
			{
				path = attackBoxDataController->GetPath(data->GetSpriteType());
			}

			std::stringstream ss;

			//start of whole obj
			ss << "{" << std::endl;

			const auto& vec_AABB_Sets = data->Get_AABB_Sets();

			for (auto i = vec_AABB_Sets.begin(); i != vec_AABB_Sets.end(); ++i)
			{
				AABB_Set* AABBs = (AABB_Set*)&*i;
				const std::string& frameName = AABBs->GetFrameName();

				ss << "    \"" << frameName << "\":" << std::endl;
				ss << "    [" << std::endl;

				const auto& vecAABB = AABBs->GetSelector()->GetVector();

				for (auto i = vecAABB.begin(); i != vecAABB.end(); ++i)
				{
					Collisions::AABB aabb = *i;

					ss << "        {" << std::endl;
					ss << "        \"posX\" : " << aabb.GetBottomLeft().x << "," << std::endl;
					ss << "        \"posY\" : " << aabb.GetBottomLeft().y << "," << std::endl;
					ss << "        \"width\" : " << aabb.GetWidthHeight().x << "," << std::endl;
					ss << "        \"height\" : " << aabb.GetWidthHeight().y << std::endl;

					if (i != AABBs->GetSelector()->GetVector().end() - 1)
					{
						ss << "        }," << std::endl;
					}
					else
					{
						ss << "        }" << std::endl;
					}
				}

				//no comma for last frame
				if (i != vec_AABB_Sets.end() - 1)
				{
					ss << "    ]," << std::endl << std::endl;
				}
				else
				{
					ss << "    ]" << std::endl;
				}
			}

			//end of whole obj
			ss << "}";

			_writer.WriteToLogFile(path, ss.str(), true); 

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

		Sprites::SpriteType currentSpriteType = Sprites::SpriteType::NONE;
		Sprites::SpriteType nextSpriteType = Sprites::SpriteType::NONE;

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (upCycle || downCycle)
		{
			// get current sprite type
			Players::iPlayer* player = playerController->GetPlayer(Players::PlayerID::PLAYER_1);
			Players::PlayerState* ownerState = Players::PlayerState::GetPlayerState(Players::PlayerID::PLAYER_1);

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

		if (nextSpriteType._value >= Sprites::SpriteType::FIGHTER_0_SPRITES_END)
		{
			nextSpriteType._value = Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1;
		}
		else if (nextSpriteType._value <= Sprites::SpriteType::FIGHTER_0_SPRITES_START)
		{
			nextSpriteType._value = Sprites::SpriteType::FIGHTER_0_SPRITES_END - 1;
		}

		if (upCycle || downCycle)
		{
			std::cout << std::endl;
			std::cout << "current sprite: " << currentSpriteType._to_string() << std::endl;
			std::cout << "next sprite: " << nextSpriteType._to_string() << std::endl;

			std::string path = "";

			if (_boxType == HBox::HBoxType::ATTACK_BOX)
			{
				path = "../resource/EditorSettings/AttackBoxSettings.editorSettings";
			}
			else if (_boxType == HBox::HBoxType::TARGET_BOX)
			{
				path = "../resource/EditorSettings/TargetBoxSettings.editorSettings";
			}
			
			// save current selection

			std::stringstream ss;

			ss << "{" << std::endl;
			ss << "\"AttackBoxEditorSettings\":" << std::endl;
			ss << "        {" << std::endl;
			ss << "            \"sprite enum\" : \"" << nextSpriteType << "\"," << std::endl;
			ss << "            \"other shit\" : \"shit\"" << std::endl;
			ss << "        }" << std::endl;
			ss << "}" << std::endl;

			_writer.WriteToLogFile(path, ss.str(), true);

			// reload updater
			if (upCycle || downCycle)
			{
				if (_boxType == HBox::HBoxType::ATTACK_BOX)
				{
					Updaters::ptrCurrentPlayground->QueueAttackBoxEditorUpdater();
				}
				else if (_boxType == HBox::HBoxType::TARGET_BOX)
				{
					Updaters::ptrCurrentPlayground->QueueTargetBoxEditorUpdater();
				}
			}
		}
	}
}
