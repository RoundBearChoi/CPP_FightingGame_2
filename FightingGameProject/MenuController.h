#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "ActiveControllers.h"
#include "SpriteDataController.h"
#include "PlayerController.h"

namespace RB::HBE::Menu
{
	class MenuController : public RB::Controllers::ControllerBase
	{
	public:
		MenuController();
		~MenuController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		RB::Sprites::SpriteEnum GetCurrentSpriteEnum();
		std::string GetCurrentSpriteString();

	private:
		RB::Sprites::SpriteDataController* _spriteDataController = nullptr;
		RB::Players::PlayerController* _playerController = nullptr;
		
	};
}