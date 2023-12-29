#pragma once
#include <string>

#include "iMenuController.h"
#include "SpriteEnum.h"

#include "HBox_Layer_1.h"

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
		RB::HBox::HBox_Layer_1* _Get_L1();

		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::string _none = "none";
		std::string _fileSaved = "File saved: ";
		int _notificationFrameCount = 0;
	};
}