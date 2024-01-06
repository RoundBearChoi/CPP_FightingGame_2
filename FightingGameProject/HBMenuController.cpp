#include "HBMenuController.h"

#include "PlayerState.h"

#include "iSpriteDataController.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iHBoxEditController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"

namespace RB::HBox
{
	void HBMenuController::Init()
	{

	}

	void HBMenuController::OnUpdate()
	{
		if (RB::Sprites::iSpriteDataController::instance == nullptr)
		{
			return;
		}

		if (RB::Players::iPlayerController::instance == nullptr ||
			RB::Render::iPlayerAnimationController::instance == nullptr)
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

		//olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 260 }, "current animation: " + _GetCurrentSpriteString(), olc::YELLOW);
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

	RB::Sprites::SpriteEnum HBMenuController::_GetCurrentSpriteEnum()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return RB::Sprites::SpriteEnum::NONE;
		}

		state->GetSpriteEnum();
		return state->GetSpriteEnum();
	}

	unsigned int HBMenuController::_GetCurrentAnimationFrame()
	{
		RB::Sprites::SpriteEnum spriteType = _GetCurrentSpriteEnum();

		RB::Render::iAnimationObj* obj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, spriteType);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}

	RB::HBox::Loaded_HB_Data* HBMenuController::_GetHBData()
	{
		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::instance->GetHBoxType();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iHurtBoxDataController::instance->GetData(_GetCurrentSpriteEnum());
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iHitBoxDataController::instance->GetData(_GetCurrentSpriteEnum());
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

		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::instance->GetHBoxType();

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance != nullptr)
			{
				const std::string& path = RB::HBox::iHurtBoxDataController::instance->GetPath(_GetCurrentSpriteEnum());
				_notification.OnUpdate("File saved: " + path);
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				const std::string& path = RB::HBox::iHitBoxDataController::instance->GetPath(_GetCurrentSpriteEnum());
				_notification.OnUpdate("File saved: " + path);
			}
		}
	}
}