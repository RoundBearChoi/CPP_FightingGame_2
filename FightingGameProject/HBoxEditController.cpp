#include "HBoxEditController.h"

namespace RB::HBox
{
	HBoxEditController::HBoxEditController(RB::HBox::HBoxType boxType)
	{
		HURTBOX_EDIT_CONTROLLER = this;

		_boxType = boxType;
	}

	HBoxEditController::~HBoxEditController()
	{
		HURTBOX_EDIT_CONTROLLER = nullptr;
	}

	void HBoxEditController::Init()
	{

	}

	void HBoxEditController::OnUpdate()
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

	void HBoxEditController::OnFixedUpdate()
	{

	}
}