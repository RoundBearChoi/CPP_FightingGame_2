#pragma once
#include <cstdint>
#include "Time.h"

#include "iPlayerController.h"
#include "HBoxEditControllerBase.h"
#include "iMenuController.h"
#include "iPlayerAnimationController.h"
#include "iHurtBoxDataController.h"
#include "iCamController.h"

#include "ActivePlayerStates.h"
#include "PlayerState.h"

namespace RB::HBox
{
	class HurtBoxEditController : public HBoxEditControllerBase
	{
	public:
		HurtBoxEditController();
		~HurtBoxEditController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}