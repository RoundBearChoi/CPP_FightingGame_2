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

		if (_getter_playerController.GetController() == nullptr ||
			_getter_playerAnimationController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr)
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

		for (size_t i = 0; i < count; i++)
		{
			RB::Collisions::AABB& aabb = data->GetAABB(i);

			//olc::vf2d pos = aabb.GetBottomLeft() + player->GetPosition();
			//_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, aabb.GetWidthHeight(), pos, olc::MAGENTA, RB::Sprites::PivotType::BOTTOM_LEFT);
		}

		_UpdateSelectedIndex(count);
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