
#include "HBoxEditController.h"

namespace RB::HBox
{
	HBoxEditController* HURTBOX_EDIT_CONTROLLER = nullptr;

	RB::HBox::HBoxDataList* HBoxEditController::GetCurrentHurtBoxDataList(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iPlayerAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HBox::HBoxDataList* dataList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(spriteEnum);

		return dataList;
	}

	RB::HBox::HBoxData* HBoxEditController::GetCurrentHurtBoxData(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return nullptr;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iPlayerAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return nullptr;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HBox::HBoxDataList* dataList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(spriteEnum);
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
}