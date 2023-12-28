#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"

#include "iPlayerController.h"
#include "iMenuController.h"
#include "iPlayerAnimationController.h"
#include "iSpriteDataController.h"
#include "iHBoxEditController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"

#include "PlayerState.h"

namespace RB::HBox
{
	class MenuController : public iMenuController
	{
	public:
		MenuController() = default;
		~MenuController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void ShowNotification() override;

	private:
		const std::string& _GetCurrentSpriteString();
		const std::string& _GetFrameName();
		RB::Sprites::SpriteEnum _GetCurrentSpriteEnum();
		unsigned int _GetCurrentAnimationFrame();
		//unsigned int _GetAABBCount();
		RB::HBox::HBoxDataList* _getList();

		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::string _none = "none";
		std::string _fileSaved = "File saved: ";
		int _notificationFrameCount = 0;
	};
}