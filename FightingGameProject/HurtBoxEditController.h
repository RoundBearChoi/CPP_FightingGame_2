#pragma once
#include <cstdint>
#include "ControllerBase.h"
#include "Time.h"

#include "ActiveControllers.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"
#include "CamController.h"

namespace RB::HurtBox
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
		RB::HurtBox::HurtBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID);
		RB::Collisions::AABB* GetCurrentAABB(RB::HurtBox::HurtBoxData* data);

	private:
		void _AddAABB_OnPress(RB::HurtBox::HurtBoxData* data);
		void _RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID);
		void _EditAABB_OnPress(RB::Collisions::AABB* aabb);
		void _UpdateSelectedIndex(size_t count);

	private:
		size_t _selectedIndex = 0;

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		RB::Controllers::ControllerGetter<RB::Render::PlayerAnimationController> _getter_playerAnimationController;
		RB::Controllers::ControllerGetter<RB::HurtBox::HurtBoxDataController> _getter_hurtBoxDataController;
		RB::Controllers::ControllerGetter<RB::Cam::CamController> _getter_camController;
	};
}