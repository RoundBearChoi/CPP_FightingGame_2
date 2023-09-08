
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
}