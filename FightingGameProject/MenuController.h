#pragma once
#include <string>

#include "iMenuController.h"
#include "SpriteEnum.h"

#include "Loaded_HB_Data.h"

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
		RB::HBox::Loaded_HB_Data* _GetHBData();

		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::string _none = "none";
		std::string _fileSaved = "File saved: ";
		int _notificationFrameCount = 0;
	};
}