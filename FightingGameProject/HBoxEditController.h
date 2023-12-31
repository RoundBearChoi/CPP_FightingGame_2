#pragma once
#include "iHBoxEditController.h"
#include "HBoxType.h"
#include "AABB_Set.h"
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

		RB::HBox::Loaded_HB_Data* GetCurrentData(RB::Players::PlayerID playerID, HBoxType boxType) override;
		RB::HBox::AABB_Set* GetCurrentHBoxData(RB::Players::PlayerID playerID) override;
		RB::HBox::HBoxType GetHBoxType() override;

	private:
		bool _ControllersExist();
		void _RenderCircleOnAABB(RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress();
		void _EditAABB_OnPress(RB::Players::PlayerID playerID);
		void _SaveHBoxes_OnPress();

	private:
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
	};
}