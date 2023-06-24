#pragma once
#include <iostream>
#include <cstdint>
#include "olcPixelGameEngine.h"

#include "ActivePlayerStates.h"

#include "iPlayerController.h"
#include "iMenuController.h"

#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"
#include "SpriteDataController.h"

namespace RB::HBox
{
	class MenuController : public iMenuController
	{
	public:
		MenuController();
		~MenuController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void ShowNotification() override;

	private:
		const std::string& _GetCurrentSpriteString();
		const std::string& _GetFrameName();
		RB::Sprites::SpriteEnum _GetCurrentSpriteEnum();
		int32_t _GetCurrentAnimationFrame();
		size_t _GetAABBCount();

		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::string _none = "none";
		std::string _fileSaved = "File saved: ";
		int32_t _notificationFrameCount = 0;
	};
}