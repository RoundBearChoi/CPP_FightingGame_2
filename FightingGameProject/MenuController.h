#pragma once
#include <iostream>
#include <cstdint>
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"

#include "ActivePlayerStates.h"

#include "ControllerGetter.h"
#include "SpriteDataController.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"

namespace RB::HBox
{
	class MenuController : public RB::Controllers::ControllerBase
	{
	public:
		MenuController();
		~MenuController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void ShowNotification();

	private:
		const std::string& _GetCurrentSpriteString();
		const std::string& _GetFrameName();
		RB::Sprites::SpriteEnum _GetCurrentSpriteEnum();
		int32_t _GetCurrentAnimationFrame();
		size_t _GetAABBCount();

		RB::Controllers::ControllerGetter<RB::Sprites::SpriteDataController> _getter_sprDataController;
		//RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		//RB::Controllers::ControllerGetter<RB::Render::PlayerAnimationController> _getter_pAniController;
		//RB::Controllers::ControllerGetter<RB::HBox::HurtBoxDataController> _getter_hurtBoxDataController;

		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::string _none = "none";
		std::string _fileSaved = "File saved: ";
		int32_t _notificationFrameCount = 0;
	};
}