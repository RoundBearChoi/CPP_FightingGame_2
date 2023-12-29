#pragma once
#include "Time.h"
#include "HBox_Layer_1.h"
#include "AABB.h"
#include "PlayerID.h"
#include "PlayerState.h"

#include "iAnimationObj.h"
#include "iHBoxEditController.h"
#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"
#include "iCamController.h"
#include "iMenuController.h"

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

		RB::HBox::HBox_Layer_1* GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType) override;
		RB::HBox::HBox_Layer_0* GetCurrentHBoxData(RB::Players::PlayerID playerID) override;
		RB::HBox::HBoxType GetHBoxType() override;

	private:
		bool _ControllersExist();
		void _UpdateSelectedIndex_OnPress(RB::HBox::HBox_Layer_0* L0);
		void _RenderCircleOnAABB(RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress();
		void _EditAABB_OnPress(RB::Players::PlayerID playerID);
		void _SaveHBoxes_OnPress();

	private:
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
	};
}