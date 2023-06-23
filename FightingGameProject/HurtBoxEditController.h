#pragma once
#include <cstdint>
#include "ControllerBase.h"
#include "Time.h"

//#include "ActiveControllers.h"
#include "ControllerGetter.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"
#include "MenuController.h"
#include "CamController.h"

namespace RB::HBox
{
	class HurtBoxEditController : public RB::Controllers::ControllerBase
	{
	public:
		HurtBoxEditController() = default;
		~HurtBoxEditController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		RB::HBox::HBoxDataSet* GetCurrentHurtBoxDataSet(RB::Players::PlayerID playerID);
		RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID);
		RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data);

	private:
		void _RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID);
		void _Add_Delete_AABB_OnPress(RB::HBox::HBoxData* data);
		void _EditAABB_OnPress(RB::Collisions::AABB* aabb);
		void _UpdateSelectedIndex_OnPress(size_t count);
		void _SaveSet_OnPress(RB::HBox::HBoxDataSet* set);

	private:
		size_t _selectedIndex = 0;

	private:
		RB::Controllers::ControllerGetter<RB::HBox::MenuController> _getter_menuController;
		RB::Controllers::ControllerGetter<RB::Cam::CamController> _getter_camController;
	};
}