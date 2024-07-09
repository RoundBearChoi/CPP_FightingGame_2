#pragma once
#include <string>

#include "SpriteType.h"

#include "iHBMenuController.h"

#include "Notification.h"
#include "Loaded_HB_Data.h"

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
