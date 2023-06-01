#include "MenuController.h"

namespace RB::HurtBox
{
	MenuController::MenuController()
	{
		SetHash(typeid(*this));
	}

	void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		_getter_pAniController.OnUpdate();
		_getter_playerController.OnUpdate();
		_getter_sprDataController.OnUpdate();
		_getter_hurtBoxDataController.OnUpdate();

		if (_getter_pAniController.GetController() == nullptr ||
			_getter_playerController.GetController() == nullptr ||
			_getter_sprDataController.GetController() == nullptr ||
			_getter_hurtBoxDataController.GetController() == nullptr)
		{
			return;
		}

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "O, P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "Q, E : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data", olc::WHITE);

		//debug
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 220 }, "current animation: " + _GetCurrentSpriteString(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 240 }, "current animation frame: " + std::to_string(_GetCurrentAnimationFrame()), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 260 }, "FrameName: " + _GetFrameName(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 280 }, "AABB count: " + std::to_string(_GetAABBCount()), olc::YELLOW);
	}

	void MenuController::OnFixedUpdate()
	{

	}

	const std::string& MenuController::_GetCurrentSpriteString()
	{
		RB::Sprites::SpriteEnum se = _GetCurrentSpriteEnum();

		const std::string& str = _getter_sprDataController.GetController()->GetString(se);

		return str;
	}

	const std::string& MenuController::_GetFrameName()
	{
		RB::HurtBox::HurtBoxDataSet* set = _getter_hurtBoxDataController.GetController()->GetDataSet(_currentSpriteEnum);

		if (set == nullptr)
		{
			return _none;
		}

		RB::HurtBox::HurtBoxData* data = set->GetHurtBoxDataByFrame(_GetCurrentAnimationFrame());

		if (data == nullptr)
		{
			return _none;
		}

		data->GetFrameName();
	}

	RB::Sprites::SpriteEnum MenuController::_GetCurrentSpriteEnum()
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnIndex(0);
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(player->GetPlayerID());

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
		RB::Render::PlayerAnimationObj* obj = _getter_pAniController.GetController()->GetAnimationObj(RB::Players::PlayerID::PLAYER_1, _currentSpriteEnum);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}

	size_t MenuController::_GetAABBCount()
	{
		RB::HurtBox::HurtBoxDataSet* set = _getter_hurtBoxDataController.GetController()->GetDataSet(_currentSpriteEnum);

		if (set == nullptr)
		{
			return 0;
		}

		RB::HurtBox::HurtBoxData* data = set->GetHurtBoxDataByFrame(_GetCurrentAnimationFrame());

		if (data == nullptr)
		{
			return 0;
		}

		return data->GetAABBCount();
	}
}