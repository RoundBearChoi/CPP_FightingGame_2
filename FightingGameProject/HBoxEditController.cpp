#include "HBoxEditController.h"

namespace RB::HBox
{
	HBoxEditController::HBoxEditController(RB::HBox::HBoxType boxType)
	{
		_boxType = boxType;
	}

	void HBoxEditController::Init()
	{

	}

	void HBoxEditController::OnUpdate()
	{
		if (_ControllersExist() == false)
		{
			return;
		}

		_SaveHBoxes_OnPress();
		_Add_Delete_AABB_OnPress();
		_RenderCircleOnAABB(RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(RB::Players::PlayerID::PLAYER_1);
	}

	void HBoxEditController::OnFixedUpdate()
	{

	}

	RB::HBox::HBoxDataList* HBoxEditController::GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetCurrentAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();

		//can get either hurtbox or hitbox
		RB::HBox::HBoxDataList* dataList = nullptr;

		if (boxType == HBoxType::HURT_BOX)
		{
			if (RB::HBox::HURTBOX_DATA_CONTROLLER != nullptr)
			{
				dataList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(spriteEnum);
			}
		}
		else if (boxType == HBoxType::HIT_BOX)
		{
			if (RB::HBox::HITBOX_DATA_CONTROLLER != nullptr)
			{
				dataList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(spriteEnum);
			}
		}

		return dataList;
	}

	RB::HBox::HBoxData* HBoxEditController::GetCurrentHBoxData(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetCurrentAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();

		RB::HBox::HBoxDataList* dataList = nullptr;
		
		if (_boxType == HBoxType::HURT_BOX)
		{
			dataList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(spriteEnum);
		}
		else if (_boxType == HBoxType::HIT_BOX)
		{
			dataList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(spriteEnum);
		}

		if (dataList == nullptr)
		{
			return nullptr;
		}

		RB::HBox::HBoxData* data = dataList->GetHBoxDataByFrame(currentIndex);

		return data;
	}

	RB::Collisions::AABB* HBoxEditController::GetCurrentAABB(RB::HBox::HBoxData* data)
	{
		size_t count = data->GetAABBCount();

		_UpdateSelectedIndex_OnPress(count);

		for (size_t i = 0; i < count; i++)
		{
			if (i == _selectedIndex)
			{
				RB::Collisions::AABB& aabb = data->GetAABB(i);

				return &aabb;
			}
		}

		return nullptr;
	}

	RB::HBox::HBoxType HBoxEditController::GetHBoxType()
	{
		return _boxType;
	}

	bool HBoxEditController::_ControllersExist()
	{
		if (_boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::HURTBOX_DATA_CONTROLLER == nullptr)
			{
				return false;
			}
		}
		else if (_boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::HITBOX_DATA_CONTROLLER == nullptr)
			{
				return false;
			}
		}

		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Render::PLAYER_ANIMATION_CONTROLLER == nullptr ||
			RB::HBox::MENU_CONTROLLER == nullptr ||
			RB::Cam::CAM_CONTROLLER == nullptr)
		{
			return false;
		}

		return true;
	}

	void HBoxEditController::_UpdateSelectedIndex_OnPress(size_t count)
	{
		olc::HWButton oButton = olc::Platform::ptrPGE->GetKey(olc::O);
		olc::HWButton pButton = olc::Platform::ptrPGE->GetKey(olc::P);

		if (oButton.bPressed)
		{
			_selectedIndex--;
		}

		if (pButton.bPressed)
		{
			_selectedIndex++;
		}

		if (_selectedIndex == SIZE_MAX)
		{
			_selectedIndex = count - 1;
		}
		else if (_selectedIndex >= count)
		{
			_selectedIndex = 0;
		}
	}
	void HBoxEditController::_RenderCircleOnAABB(RB::Players::PlayerID playerID)
	{
		RB::HBox::HBoxData* data = GetCurrentHBoxData(playerID);
		RB::Collisions::AABB* aabb = GetCurrentAABB(data);

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vf2d pos = player->GetPosition() + aabb->GetBottomLeft();

		olc::vf2d relPos = RB::Cam::CAM_CONTROLLER->GetCamObj()->GetRelativePosition(pos) + olc::vi2d{ 1, -1 };

		olc::Renderer::ptrPGE->DrawCircle(relPos, 3, olc::WHITE);
		olc::Renderer::ptrPGE->DrawCircle(relPos, 4, olc::WHITE);
	}

	void HBoxEditController::_Add_Delete_AABB_OnPress()
	{
		RB::HBox::HBoxData* data = GetCurrentHBoxData(RB::Players::PlayerID::PLAYER_1);

		olc::HWButton insButton = olc::Platform::ptrPGE->GetKey(olc::INS);
		olc::HWButton delButton = olc::Platform::ptrPGE->GetKey(olc::DEL);

		if (insButton.bPressed)
		{
			data->AddAABB(RB::Collisions::AABB{ 0.0f, 0.0f, 0.0f, 0.0f }); // 0, 0 by default

			_selectedIndex = data->GetAABBCount() - 1;
		}

		if (delButton.bPressed)
		{
			if (data->DeleteAABB(_selectedIndex))
			{
				_selectedIndex--;
			}
		}
	}

	void HBoxEditController::_EditAABB_OnPress(RB::Players::PlayerID playerID)
	{
		RB::HBox::HBoxData* data = GetCurrentHBoxData(playerID);
		RB::Collisions::AABB* aabb = GetCurrentAABB(data);

		if (aabb == nullptr)
		{
			return;
		}

		olc::HWButton wButton = olc::Platform::ptrPGE->GetKey(olc::W);
		olc::HWButton sButton = olc::Platform::ptrPGE->GetKey(olc::S);

		olc::HWButton aButton = olc::Platform::ptrPGE->GetKey(olc::A);
		olc::HWButton dButton = olc::Platform::ptrPGE->GetKey(olc::D);

		float_t moveAmount = 50.0f;

		if (wButton.bHeld)
		{
			aabb->MoveY(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (sButton.bHeld)
		{
			aabb->MoveY(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (aButton.bHeld)
		{
			aabb->MoveX(-moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (dButton.bHeld)
		{
			aabb->MoveX(moveAmount * RB::Frames::Time::GetDeltaTime());
		}

		olc::HWButton uButton = olc::Platform::ptrPGE->GetKey(olc::U);
		olc::HWButton jButton = olc::Platform::ptrPGE->GetKey(olc::J);

		olc::HWButton hButton = olc::Platform::ptrPGE->GetKey(olc::H);
		olc::HWButton kButton = olc::Platform::ptrPGE->GetKey(olc::K);

		float_t sizeAmount = 40.0f;

		if (uButton.bHeld)
		{
			aabb->IncreaseHeight(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (jButton.bHeld)
		{
			aabb->IncreaseHeight(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (hButton.bHeld)
		{
			aabb->IncreaseWidth(-sizeAmount * RB::Frames::Time::GetDeltaTime());
		}

		if (kButton.bHeld)
		{
			aabb->IncreaseWidth(sizeAmount * RB::Frames::Time::GetDeltaTime());
		}
	}

	void HBoxEditController::_SaveHBoxes_OnPress()
	{
		RB::HBox::HBoxDataList* list = GetCurrentHBoxDataList(RB::Players::PlayerID::PLAYER_1, _boxType);

		olc::HWButton enterButton = olc::Platform::ptrPGE->GetKey(olc::ENTER);

		if (enterButton.bPressed)
		{
			std::cout << std::endl;
			std::cout << "saving hurtbox set" << std::endl;

			std::string path;

			if (_boxType == RB::HBox::HBoxType::HURT_BOX)
			{
				path = RB::HBox::HURTBOX_DATA_CONTROLLER->GetPath(list->GetSpriteEnum());
			}
			else if (_boxType == RB::HBox::HBoxType::HIT_BOX)
			{
				path = RB::HBox::HITBOX_DATA_CONTROLLER->GetPath(list->GetSpriteEnum());
			}

			std::ofstream file(path);

			if (file.is_open())
			{
				//start of whole obj
				file << "{" << std::endl;

				for (size_t f = 0; f < list->GetSize(); f++)
				{
					HBoxData* data = list->GetHBoxDataByFrame(f);
					const std::string& frameName = data->GetFrameName();

					file << "    \"" << frameName << "\":" << std::endl;
					file << "    [" << std::endl;

					for (size_t a = 0; a < data->GetAABBCount(); a++)
					{
						RB::Collisions::AABB aabb = data->GetAABB(a);

						file << "        {" << std::endl;
						file << "        \"posX\" : " << aabb.GetBottomLeft().x << "," << std::endl;
						file << "        \"posY\" : " << aabb.GetBottomLeft().y << "," << std::endl;
						file << "        \"width\" : " << aabb.GetWidthHeight().x << "," << std::endl;
						file << "        \"height\" : " << aabb.GetWidthHeight().y << std::endl;

						if (a != data->GetAABBCount() - 1)
						{
							file << "        }," << std::endl;
						}
						else
						{
							file << "        }" << std::endl;
						}
					}

					if (f != list->GetSize() - 1)
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

			RB::HBox::MENU_CONTROLLER->ShowNotification();
		}
	}
}