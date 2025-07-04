#pragma once

#include "AABB_Set.h"
#include "HBoxType.h"
#include "Loaded_HB_Data.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/PlayerType.h"

namespace RB::HBox
{
	#define GET_HBOX_EDIT_CONTROLLER static_cast<HBox::iHBoxEditController*>(Controllers::GetController(Controllers::ControllerType::HBOX_EDIT_CONTROLLER))

	class iHBoxEditController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual HBox::Loaded_HB_Data* GetCurrentData(Players::PLAYER_TYPE playerID, HBoxType boxType) = 0;
		virtual HBox::AABB_Set* GetCurrentHBoxData(Players::PLAYER_TYPE playerID) = 0;
		virtual HBox::HBoxType GetHBoxType() = 0;
	};
}
