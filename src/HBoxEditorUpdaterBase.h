#pragma once

#include "Vector2.h"
#include "Player.h"
#include "string"
#include "HBoxType.h"

#include "InputController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "HBox/HBMenuController.h"
#include "TargetBoxDataController.h"
#include "HBox/AttackBoxDataController.h"
#include "HBoxEditController.h"
#include "SpriteTypeLoader.h"

#include "iUpdaterObj.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	class HBoxEditorUpdaterBase : public iUpdaterObj
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
