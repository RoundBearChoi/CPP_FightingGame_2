#pragma once
#include "ControllerBase.h"
#include "HBoxDataList.h"
#include "AABB.h"
#include "PlayerID.h"

#include "PlayerState.h"
#include "ActivePlayerStates.h"
#include "iPlayerAnimationObj.h"

#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iCamController.h"

namespace RB::HBox
{
	class HBoxEditControllerBase : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataList* GetCurrentHurtBoxDataList(RB::Players::PlayerID playerID);
		virtual RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID);
		virtual RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data);

	protected:
		virtual void _UpdateSelectedIndex_OnPress(size_t count);
		virtual void _RenderCircleOnAABB(RB::Collisions::AABB* aabb, RB::Players::PlayerID playerID);
		virtual void _Add_Delete_AABB_OnPress(RB::HBox::HBoxData* data);

	protected:
		size_t _selectedIndex = 0;
	};

	extern HBoxEditControllerBase* HURTBOX_EDIT_CONTROLLER;
}