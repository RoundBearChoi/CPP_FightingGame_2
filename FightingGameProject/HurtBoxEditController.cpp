#include "HurtBoxEditController.h"

namespace RB::HurtBox
{
	void HurtBoxEditController::Init()
	{

	}

	void HurtBoxEditController::OnUpdate()
	{
		_getter_playerController.OnUpdate();
		_getter_playerAnimationController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();
		_getter_camController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr ||
			_getter_camController.GetController() == nullptr)
		{
			return;
		}

		_Edit(RB::Players::PlayerID::PLAYER_1);
	}

	void HurtBoxEditController::OnFixedUpdate()
	{

	}

	void HurtBoxEditController::_Edit(RB::Players::PlayerID playerID)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(playerID);

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::PlayerAnimationObj* aniObj = _getter_playerAnimationController.GetController()->GetAnimationObj(playerID, spriteEnum);

		if (aniObj == nullptr)
		{
			return;
		}

		int32_t currentIndex = aniObj->GetCurrentIndex();
		RB::HurtBox::HurtBoxDataSet* dataSet = _getter_hurtBoxDataController.GetController()->GetDataSet(spriteEnum);
		RB::HurtBox::HurtBoxData* data = dataSet->GetHurtBoxDataByFrame(currentIndex);

		size_t count = data->GetDataCount();

		_UpdateSelectedIndex(count);

		for (size_t i = 0; i < count; i++)
		{
			if (i == _selectedIndex)
			{
				RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

				RB::Collisions::AABB& aabb = data->GetAABB(i);

				olc::vf2d pos = player->GetPosition() + aabb.GetBottomLeft();

				olc::vi2d relPos = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(pos) + olc::vi2d{1, -1};

				olc::Renderer::ptrPGE->DrawCircle(relPos, 3, olc::WHITE);
				olc::Renderer::ptrPGE->DrawCircle(relPos, 4, olc::WHITE);
			}
		}
	}

	void HurtBoxEditController::_UpdateSelectedIndex(size_t count)
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