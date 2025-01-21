#pragma once

#include <string>

#include "UpdaterBase.h"

#include "../Vector2.h"
#include "../Players/Player.h"
#include "../HBox/HBoxType.h"
#include "../Sprites/SpriteTypeLoader.h"

#include "../Input/InputController.h"
#include "../Cam/CamController.h"
#include "../Players/PlayerController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../HBox/HBMenuController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../HBox/HBoxEditController.h"

#include "../Fighter_0_States/F0_Dummy.h"

namespace RB::Updaters
{
	class HBoxEditorUpdaterBase : public UpdaterBase
	{
	public:
		HBoxEditorUpdaterBase() = default;
		~HBoxEditorUpdaterBase() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	protected:
		std::string _settingsPath = "";
		std::string _specsPath = "";
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
		std::string _pageTitle = "HBoxEditor";
	};
}