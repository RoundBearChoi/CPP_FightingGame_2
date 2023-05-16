#include "MenuController.h"

namespace RB::HBE::Menu
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


		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp, PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "Ins, Del : create/delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "O, P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "Q, E : enlarge/shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "ENTER : save data", olc::WHITE);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 220 }, "current animation: " + GetCurrentSpriteString(), olc::YELLOW);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 240 }, "current animation frame: ", olc::YELLOW);
	}

	void MenuController::OnFixedUpdate()
	{

	}

	RB::Sprites::SpriteEnum MenuController::GetCurrentSpriteEnum()
	{
		if (_playerController == nullptr)
		{
			_playerController = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();

			return RB::Sprites::SpriteEnum::NONE;
		}

		RB::Players::iPlayer* p = _playerController->GetPlayerOnIndex(0);
		RB::Sprites::SpriteEnum se = p->GetSpriteEnum();
	}

	std::string MenuController::GetCurrentSpriteString()
	{
		if (_spriteDataController == nullptr)
		{
			_spriteDataController = RB::Controllers::ActiveControllers::GetController<RB::Sprites::SpriteDataController>();

			return "NONE";
		}

		RB::Sprites::SpriteEnum se = GetCurrentSpriteEnum();

		std::string str = _spriteDataController->GetString(se);

		return str;
	}
}