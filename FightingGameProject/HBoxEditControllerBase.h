#pragma once
#include "ControllerBase.h"
#include "HBoxDataList.h"
#include "AABB.h"
#include "PlayerID.h"
#include "Time.h"
#include "HBoxType.h"

#include "PlayerState.h"
#include "ActivePlayerStates.h"
#include "iPlayerAnimationObj.h"

#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"
#include "iCamController.h"
#include "iMenuController.h"

namespace RB::HBox
{
	class HBoxEditControllerBase : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::HBox::HBoxDataList* GetCurrentHBoxDataList(RB::Players::PlayerID playerID, HBoxType boxType);
		virtual RB::HBox::HBoxData* GetCurrentHBoxData(RB::Players::PlayerID playerID);
		virtual RB::Collisions::AABB* GetCurrentAABB(RB::HBox::HBoxData* data);

		virtual RB::HBox::HBoxType GetHBoxType();

	protected:
		virtual bool _ControllersExist();
		virtual void _UpdateSelectedIndex_OnPress(size_t count);
		virtual void _RenderCircleOnAABB(RB::Players::PlayerID playerID);
		virtual void _Add_Delete_AABB_OnPress();
		virtual void _EditAABB_OnPress(RB::Players::PlayerID playerID);
		virtual void _SaveHBoxes_OnPress();

	protected:
		size_t _selectedIndex = 0;
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
	};
}