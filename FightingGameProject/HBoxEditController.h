#pragma once
#include "iHBoxEditController.h"
#include "HBoxType.h"
#include "HBox_Layer_0.h"
#include "Loaded_HB_Data.h"
#include "PlayerID.h"

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

		RB::HBox::Loaded_HB_Data* GetCurrentL1(RB::Players::PlayerID playerID, HBoxType boxType) override;
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