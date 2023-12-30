#include "MenuController.h"

#include "PlayerState.h"

#include "iSpriteDataController.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iHBoxEditController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"

namespace RB::HBox
{
	void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
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

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "O, P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "UHJK : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data (saves the entire set)", olc::WHITE);

		if (_notificationFrameCount > 0)
		{
			std::string path;

			RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::instance->GetHBoxType();

			if (boxType == RB::HBox::HBoxType::HURT_BOX)
			{
				if (RB::HBox::iHurtBoxDataController::instance != nullptr)
				{
					path = RB::HBox::iHurtBoxDataController::instance->GetPath(_currentSpriteEnum);
				}
			}
			else if (boxType == RB::HBox::HBoxType::HIT_BOX)
			{
				if (RB::HBox::iHitBoxDataController::instance != nullptr)
				{
					path = RB::HBox::iHitBoxDataController::instance->GetPath(_currentSpriteEnum);
				}
			}

			olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 200 }, _fileSaved + path, olc::GREEN);
		}

		//debug
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 260 }, "current animation: " + _GetCurrentSpriteString(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 280 }, "current animation frame: " + std::to_string(_GetCurrentAnimationFrame()), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 300 }, "FrameName: " + _GetFrameName(), olc::YELLOW);

		RB::HBox::Loaded_HB_Data* data = _GetHBData();

		if (data == nullptr)
		{
			return;
		}

		RB::HBox::HBox_Layer_0* L0 = data->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (L0 == nullptr)
		{
			return;
		}

		auto const& vec = L0->GetSelector()->GetVector();

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 320 }, "AABB count: " + std::to_string(vec.size()), olc::YELLOW);
	}

	void MenuController::OnFixedUpdate()
	{
		if (_notificationFrameCount > 0)
		{
			_notificationFrameCount--;
		}
	}

	void MenuController::ShowNotification()
	{
		_notificationFrameCount = 120;
	}

	const std::string& MenuController::_GetCurrentSpriteString()
	{
		RB::Sprites::SpriteEnum se = _GetCurrentSpriteEnum();

		const std::string& str = RB::Sprites::iSpriteDataController::instance->GetString(se);

		return str;
	}

	const std::string& MenuController::_GetFrameName()
	{
		RB::HBox::Loaded_HB_Data* data = _GetHBData();
		
		if (data == nullptr)
		{
			return _none;
		}

		RB::HBox::HBox_Layer_0* L0 = data->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (L0 == nullptr)
		{
			return _none;
		}

		return L0->GetFrameName();
	}

	RB::Sprites::SpriteEnum MenuController::_GetCurrentSpriteEnum()
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return _currentSpriteEnum;
		}

		state->GetSpriteEnum();
		_currentSpriteEnum = state->GetSpriteEnum();

		return _currentSpriteEnum;
	}

	unsigned int MenuController::_GetCurrentAnimationFrame()
	{
		RB::Render::iAnimationObj* obj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, _currentSpriteEnum);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}

	RB::HBox::Loaded_HB_Data* MenuController::_GetHBData()
	{
		RB::HBox::HBoxType boxType = RB::HBox::iHBoxEditController::instance->GetHBoxType();

		RB::HBox::Loaded_HB_Data* data = nullptr;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::iHurtBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iHurtBoxDataController::instance->GetData(_currentSpriteEnum);
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::iHitBoxDataController::instance != nullptr)
			{
				data = RB::HBox::iHitBoxDataController::instance->GetData(_currentSpriteEnum);
			}
		}

		return data;
	}
}