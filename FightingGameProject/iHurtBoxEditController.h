#pragma once
#include "ControllerBase.h"
#include "HBoxDataset.h"
#include "AABB.h"
#include "PlayerID.h"

namespace RB::HBox
{
	class iHurtBoxEditController : public RB::Controllers::ControllerBase
	{
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataset* GetCurrentHurtBoxDataSet(RB::Players::PlayerID playerID) = 0;
		virtual RB::HBox::HBoxData* GetCurrentHurtBoxData(RB::Players::PlayerID playerID) = 0;
		virtual RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) = 0;
	};

	extern iHurtBoxEditController* HURTBOX_EDIT_CONTROLLER;
}