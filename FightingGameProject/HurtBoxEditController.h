#pragma once
#include <cstdint>
#include "Time.h"

#include "iPlayerController.h"
#include "iHurtBoxEditController.h"
#include "iMenuController.h"
#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iCamController.h"

#include "ActivePlayerStates.h"
#include "PlayerState.h"

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

		RB::HBox::HBoxDataList* GetCurrentHurtBoxDataList(RB::Players::PlayerID playerID) override;
		RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID) override;
		RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) override;

	private:
		void _RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress(RB::HBox::HBoxData* data);
		void _EditAABB_OnPress(RB::Collisions::AABB* aabb);
		void _UpdateSelectedIndex_OnPress(size_t count);
		void _SaveSet_OnPress(RB::HBox::HBoxDataList* set);

	private:
		size_t _selectedIndex = 0;
	};
}