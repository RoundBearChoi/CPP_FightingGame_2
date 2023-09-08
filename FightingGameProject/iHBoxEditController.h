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

namespace RB::HBox
{
	class iHBoxEditController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataList* GetCurrentHurtBoxDataList(RB::Players::PlayerID playerID);
		virtual RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID) = 0;
		virtual RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) = 0;
	};

	extern iHBoxEditController* HURTBOX_EDIT_CONTROLLER;
}