#pragma once

#include <string>

#include "Loaded_HB_Data.h"

#include "iAttackBoxDataController.h"
#include "iHBMenuController.h"
#include "iHBoxEditController.h"
#include "iTargetBoxDataController.h"

#include "../Sprites/SpriteType.h"
#include "../Players/PlayerState.h"
#include "../Render/Notification.h"

#include "../Sprites/GetCurrentSpriteType.h"
#include "../Sprites/GetCurrentAnimationFrame.h"

#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"

namespace RB::HBox
{
	class HBMenuController : public iHBMenuController
	{
	public:
		HBMenuController(std::string pageTitle);
		~HBMenuController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void ShowNotification() override;
		void SetPageTitle(std::string title) override;

	private:
		const std::string& _GetFrameName();
		HBox::Loaded_HB_Data* _GetHBData();
		void _ShowSavedNotification();

		std::string _none = "none";
		std::string _pageTitle = "HBoxEditor";
		Render::Notification _notification;
	};
}
