#pragma once
#include "ControllerBase.h"
#include "HBoxDataList.h"
#include "HBoxData.h"
#include "HBoxType.h"
#include "PlayerID.h"

namespace RB::HBox
{
	class iHBoxEditController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataList* GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType) = 0;
		virtual RB::HBox::HBoxData* GetCurrentHBoxData(RB::Players::PlayerID playerID) = 0;
		virtual RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data) = 0;
		virtual RB::HBox::HBoxType GetHBoxType() = 0;
	};

	extern iHBoxEditController* HBOX_EDIT_CONTROLLER;
}