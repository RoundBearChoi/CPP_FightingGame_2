#pragma once

#include <fstream>

#include "HBoxType.h"
#include "AABB_Set.h"

#include "iAttackBoxDataController.h"
#include "iHBMenuController.h"
#include "iHBoxEditController.h"
#include "iTargetBoxDataController.h"
#include "Loaded_HB_Data.h"

#include "../Time.h"
#include "../Vector2.h"
#include "../PlayerID.h"
#include "../PlayerState.h"
#include "../CurrentUpdater.h"

#include "../CircleRenderer.h"
#include "../iUpdater.h"
#include "../iPlayerController.h"
#include "../iPlayerAnimationController.h"
#include "../iCamController.h"

namespace RB::HBox
{
	class HBoxEditController : public RB::HBox::iHBoxEditController
	{
	public:
		HBoxEditController(RB::HBox::HBoxType boxType);
		~HBoxEditController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		RB::HBox::Loaded_HB_Data* GetCurrentData(RB::Players::PlayerID playerID, HBoxType boxType) override;
		RB::HBox::AABB_Set* GetCurrentHBoxData(RB::Players::PlayerID playerID) override;
		RB::HBox::HBoxType GetHBoxType() override;

	private:
		bool _ControllersExist();
		void _RenderCircleOnHBox(RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress();
		void _EditAABB_OnPress(RB::Players::PlayerID playerID);
		void _SaveHBoxes_OnPress();
		void _CycleAnimations_OnPress();

	private:
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
		RB::Render::CircleRenderer _circleRenderer;
	};
}
