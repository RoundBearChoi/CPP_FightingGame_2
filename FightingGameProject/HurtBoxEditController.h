#pragma once
#include <cstdint>
#include "Time.h"

#include "iPlayerController.h"
#include "iHurtBoxEditController.h"
#include "HurtBoxDataController.h"
#include "CamController.h"
#include "PlayerAnimationController.h"
#include "MenuController.h"

namespace RB::HBox
{
	class HurtBoxEditController : public iHurtBoxEditController
	{
	public:
		HurtBoxEditController();
		~HurtBoxEditController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		RB::HBox::HBoxDataSet* GetCurrentHurtBoxDataSet(RB::Players::PlayerID playerID) override;
		RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID) override;
		RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) override;

	private:
		void _RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress(RB::HBox::HBoxData* data);
		void _EditAABB_OnPress(RB::Collisions::AABB* aabb);
		void _UpdateSelectedIndex_OnPress(size_t count);
		void _SaveSet_OnPress(RB::HBox::HBoxDataSet* set);

	private:
		size_t _selectedIndex = 0;
	};
}