#pragma once

#include "AABB_Set.h"
#include "HBoxType.h"
#include "Loaded_HB_Data.h"

#include "../Controllers/ControllerT.h"
#include "../Players/PlayerID.h"

namespace RB::HBox
{
	class iHBoxEditController : public RB::Controllers::ControllerT<iHBoxEditController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::Loaded_HB_Data* GetCurrentData(RB::Players::PlayerID playerID, HBoxType boxType) = 0;
		virtual RB::HBox::AABB_Set* GetCurrentHBoxData(RB::Players::PlayerID playerID) = 0;
		virtual RB::HBox::HBoxType GetHBoxType() = 0;
	};
}
