#pragma once
#include <cstdint>
#include "ControllerBase.h"

#include "ActiveControllers.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"

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

	private:
		void _Edit(RB::Players::PlayerID playerID);
		void _UpdateSelectedIndex(size_t count);

	private:
		size_t _selectedIndex = 0;

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		RB::Controllers::ControllerGetter<RB::Render::PlayerAnimationController> _getter_playerAnimationController;
		RB::Controllers::ControllerGetter<RB::HurtBox::HurtBoxDataController> _getter_hurtBoxDataController;
	};
}