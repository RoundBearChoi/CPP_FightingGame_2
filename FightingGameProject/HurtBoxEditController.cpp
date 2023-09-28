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

		RB::HBox::HBoxDataList* list = GetCurrentHBoxDataList(RB::Players::PlayerID::PLAYER_1, HBoxType::HURT_BOX);
		RB::HBox::HBoxData* data = GetCurrentHBoxData(RB::Players::PlayerID::PLAYER_1);
		RB::Collisions::AABB* aabb = GetCurrentAABB(data);

		_SaveHurtBoxes_OnPress(list);
		_Add_Delete_AABB_OnPress(data);
		_RenderCircleOnAABB(aabb, RB::Players::PlayerID::PLAYER_1);
		_EditAABB_OnPress(aabb);

	}

	void HurtBoxEditController::OnFixedUpdate()
	{

	}
}