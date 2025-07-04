#pragma once

#include <fstream>

#include "HBoxType.h"
#include "AABB_Set.h"
#include "Loaded_HB_Data.h"

#include "iAttackBoxDataController.h"
#include "iHBMenuController.h"
#include "iHBoxEditController.h"
#include "iTargetBoxDataController.h"

#include "../Writer.h"

#include "../Time.h"
#include "../Vector2.h"
#include "../Players/PlayerType.h"
#include "../Players/PlayerState.h"
#include "../Updaters/CurrentPlayground.h"
#include "../Render/CircleRenderer.h"

#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"
#include "../Cam/iCamController.h"

namespace RB::HBox
{
	class HBoxEditController : public HBox::iHBoxEditController
	{
	public:
		HBoxEditController(HBox::HBoxType boxType);
		~HBoxEditController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBox::Loaded_HB_Data* GetCurrentData(Players::PLAYER_TYPE playerID, HBoxType boxType) override;
		HBox::AABB_Set* GetCurrentHBoxData(Players::PLAYER_TYPE playerID) override;
		HBox::HBoxType GetHBoxType() override;

	private:
		bool _ControllersExist();
		void _RenderCircleOnHBox(Players::PLAYER_TYPE playerID);
		void _Add_Delete_AABB_OnPress();
		void _EditAABB_OnPress(Players::PLAYER_TYPE playerID);
		void _SaveHBoxes_OnPress();
		void _CycleAnimations_OnPress();

	private:
		HBox::HBoxType _boxType = HBox::HBoxType::NONE;
		Render::CircleRenderer _circleRenderer;
		RB::Writer _writer;
	};
}
