#include "HBoxEditControllerBase.h"

namespace RB::HBox
{
	HBoxEditControllerBase* HURTBOX_EDIT_CONTROLLER = nullptr;

	RB::HBox::HBoxDataList* HBoxEditControllerBase::GetCurrentHurtBoxDataList(RB::Players::PlayerID playerID)
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

	RB::HBox::HBoxData* HBoxEditControllerBase::GetCurrentHurtBoxData(RB::Players::PlayerID playerID)
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

	RB::Collisions::AABB* HBoxEditControllerBase::GetCurrentAABB(RB::HBox::HBoxData* data)
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

	void HBoxEditControllerBase::_UpdateSelectedIndex_OnPress(size_t count)
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
	void HBoxEditControllerBase::_RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID)
	{
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

	void HBoxEditControllerBase::_Add_Delete_AABB_OnPress(RB::HBox::HBoxData* data)
	{
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

	void HBoxEditControllerBase::_EditAABB_OnPress(RB::Collisions::AABB* aabb)
	{
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
}