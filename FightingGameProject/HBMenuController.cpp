#include "HBMenuController.h"

#include "PlayerState.h"

#include "iSpriteDataController.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iHBoxEditController.h"
#include "iTargetBoxDataController.h"
#include "iAttackBoxDataController.h"

namespace RB::HBox
{
	void HBMenuController::Init()
	{

	}

	void HBMenuController::OnUpdate()
	{
		if (RB::Sprites::iSpriteDataController::Get() == nullptr)
		{
			return;
		}

		if (RB::Players::iPlayerController::Get() == nullptr ||
			RB::Render::iPlayerAnimationController::Get() == nullptr)
		{
			return;
		}

		_ShowSavedNotification();

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "O, P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "UHJK : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data (saves the entire set)", olc::WHITE);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 280 }, "current animation frame: " + std::to_string(_GetCurrentAnimationFrame()), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 300 }, "FrameName: " + _GetFrameName(), olc::YELLOW);

		RB::HBox::Loaded_HB_Data* data = _GetHBData();

		if (data == nullptr)
		{
			return;
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (AABBs == nullptr)
		{
			return;
		}

		auto const& vec = AABBs->GetSelector()->GetVector();

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 320 }, "AABB count: " + std::to_string(vec.size()), olc::YELLOW);
	}

	void HBMenuController::OnFixedUpdate()
	{
		_notification.OnFixedUpdate();
	}

	void HBMenuController::ShowNotification()
	{
		_notification.AddFrameCount(120);
	}

	const std::string& HBMenuController::_GetFrameName()
	{
		RB::HBox::Loaded_HB_Data* data = _GetHBData();
		
		if (data == nullptr)
		{
			return _none;
		}

		RB::HBox::AABB_Set* AABBs = data->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (AABBs == nullptr)
		{
			return _none;
		}

		return AABBs->GetFrameName();
	}

	RB::Sprites::SpriteType HBMenuController::_GetCurrentSpriteType()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return RB::Sprites::SpriteType::NONE;
		}

		state->GetSpriteType();
		return state->GetSpriteType();
	}

	unsigned int HBMenuController::_GetCurrentAnimationFrame()
	{
		RB::Sprites::SpriteType spriteType = _GetCurrentSpriteType();

		RB::Render::iAnimationObj* obj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, spriteType);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}

	RB::HBox::Loaded_HB_Data* HBMenuController::_GetHBData()
	{
		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::Get()->GetHBoxType();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iTargetBoxDataController::Get()->GetData(_GetCurrentSpriteType());
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (RB::HBox::iAttackBoxDataController::Get() != nullptr)
			{
				data = RB::HBox::iAttackBoxDataController::Get()->GetData(_GetCurrentSpriteType());
			}
		}

		return data;
	}

	void HBMenuController::_ShowSavedNotification()
	{
		if (_notification.GetFrameCount() == 0)
		{
			return;
		}

		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::Get()->GetHBoxType();

		if (boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			if (RB::HBox::iTargetBoxDataController::Get() != nullptr)
			{
				const std::string& path = RB::HBox::iTargetBoxDataController::Get()->GetPath(_GetCurrentSpriteType());
				_notification.OnUpdate("File saved: " + path);
			}
		}
		else if (boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			if (RB::HBox::iAttackBoxDataController::Get() != nullptr)
			{
				const std::string& path = RB::HBox::iAttackBoxDataController::Get()->GetPath(_GetCurrentSpriteType());
				_notification.OnUpdate("File saved: " + path);
			}
		}
	}
}