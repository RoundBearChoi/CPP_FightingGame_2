#include "MenuController.h"

namespace RB::HBox
{
	MenuController::MenuController()
	{
		MENU_CONTROLLER = this;
	}

	MenuController::~MenuController()
	{
		MENU_CONTROLLER = nullptr;
	}

	void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		if (RB::Sprites::SPRITE_DATA_CONTROLLER == nullptr)
		{
			return;
		}

		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::Render::PLAYER_ANIMATION_CONTROLLER == nullptr)
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

			RB::HBox::HBoxType boxType = RB::HBox::HBOX_EDIT_CONTROLLER->GetHBoxType();

			if (boxType == RB::HBox::HBoxType::HURT_BOX)
			{
				if (RB::HBox::HURTBOX_DATA_CONTROLLER != nullptr)
				{
					path = RB::HBox::HURTBOX_DATA_CONTROLLER->GetPath(_currentSpriteEnum);
				}
			}
			else if (boxType == RB::HBox::HBoxType::HIT_BOX)
			{
				if (RB::HBox::HITBOX_DATA_CONTROLLER != nullptr)
				{
					path = RB::HBox::HITBOX_DATA_CONTROLLER->GetPath(_currentSpriteEnum);
				}
			}

			olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 200 }, _fileSaved + path, olc::GREEN);
		}

		//debug
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 260 }, "current animation: " + _GetCurrentSpriteString(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 280 }, "current animation frame: " + std::to_string(_GetCurrentAnimationFrame()), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 300 }, "FrameName: " + _GetFrameName(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 320 }, "AABB count: " + std::to_string(_GetAABBCount()), olc::YELLOW);
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

		const std::string& str = RB::Sprites::SPRITE_DATA_CONTROLLER->GetString(se);

		return str;
	}

	const std::string& MenuController::_GetFrameName()
	{
		RB::HBox::HBoxDataList* list = _getList();
		
		if (list == nullptr)
		{
			return _none;
		}

		RB::HBox::HBoxData* data = list->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (data == nullptr)
		{
			return _none;
		}

		return data->GetFrameName();
	}

	RB::Sprites::SpriteEnum MenuController::_GetCurrentSpriteEnum()
	{
		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return _currentSpriteEnum;
		}

		state->GetSpriteEnum();
		_currentSpriteEnum = state->GetSpriteEnum();

		return _currentSpriteEnum;
	}

	int32_t MenuController::_GetCurrentAnimationFrame()
	{
		RB::Render::iAnimationObj* obj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, _currentSpriteEnum);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}

	size_t MenuController::_GetAABBCount()
	{
		RB::HBox::HBoxDataList* list = _getList();

		if (list == nullptr)
		{
			return 0;
		}

		RB::HBox::HBoxData* data = list->GetHBoxDataByFrame(_GetCurrentAnimationFrame());

		if (data == nullptr)
		{
			return 0;
		}

		return data->GetAABBCount();
	}

	RB::HBox::HBoxDataList* MenuController::_getList()
	{
		RB::HBox::HBoxType boxType = RB::HBox::HBOX_EDIT_CONTROLLER->GetHBoxType();

		RB::HBox::HBoxDataList* list = nullptr;

		if (boxType == RB::HBox::HBoxType::HURT_BOX)
		{
			if (RB::HBox::HURTBOX_DATA_CONTROLLER != nullptr)
			{
				list = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(_currentSpriteEnum);
			}
		}
		else if (boxType == RB::HBox::HBoxType::HIT_BOX)
		{
			if (RB::HBox::HITBOX_DATA_CONTROLLER != nullptr)
			{
				list = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(_currentSpriteEnum);
			}
		}

		return list;
	}
}