#pragma once
#include "ControllerT.h"

#include "HBoxDataList.h"
#include "HBox_Layer_0.h"
#include "HBoxType.h"
#include "PlayerID.h"

namespace RB::HBox
{
	class iHBoxEditController : public RB::Controllers::ControllerT<iHBoxEditController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataList* GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType) = 0;
		virtual RB::HBox::HBox_Layer_0* GetCurrentHBoxData(RB::Players::PlayerID playerID) = 0;
		virtual RB::HBox::HBoxType GetHBoxType() = 0;
	};
}