#include "HurtBoxEditController.h"

namespace RB::HBox
{
	HurtBoxEditController::HurtBoxEditController()
	{
		HURTBOX_EDIT_CONTROLLER = this;
	}

	HurtBoxEditController::~HurtBoxEditController()
	{
		HURTBOX_EDIT_CONTROLLER = nullptr;
	}

	void HurtBoxEditController::Init()
	{

	}

	void HurtBoxEditController::OnUpdate()
	{
		if (_ControllersExist() == false)
		{
			return;
		}

		_SaveHurtBoxes_OnPress();
		_Add_Delete_AABB_OnPress();
		_RenderCircleOnAABB(RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(RB::Players::PlayerID::PLAYER_1);

	}

	void HurtBoxEditController::OnFixedUpdate()
	{

	}
}