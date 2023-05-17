#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "ActiveControllers.h"
#include "SpriteDataController.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"

namespace RB::HurtBox
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
		const std::string& GetCurrentSpriteString();
		int32_t GetCurrentFrame();

	private:
		RB::Sprites::SpriteDataController* _spriteDataController = nullptr;
		RB::Players::PlayerController* _playerController = nullptr;
		RB::Render::PlayerAnimationController* _playerAnimationController = nullptr;
		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}