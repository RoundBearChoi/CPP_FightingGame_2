#pragma once
#include <string>

#include "SpriteType.h"
#include "PlayerState.h"
#include "Notification.h"
#include "Loaded_HB_Data.h"

#include "GetCurrentSpriteType.h"
#include "GetCurrentAnimationFrame.h"

#include "iHBMenuController.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iHBoxEditController.h"
#include "iTargetBoxDataController.h"
#include "iAttackBoxDataController.h"

namespace RB::HBox
{
	class HBMenuController : public iHBMenuController
	{
	public:
		HBMenuController() = default;
		~HBMenuController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void ShowNotification() override;
		void SetPageTitle(std::string title) override;

	private:
		const std::string& _GetFrameName();
		RB::HBox::Loaded_HB_Data* _GetHBData();
		void _ShowSavedNotification();

		std::string _none = "none";
		std::string _pageTitle = "HBoxEditor";
		RB::Render::Notification _notification;
	};
}
