#pragma once

#include "iUpdaterObj.h"

#include "../Vector2.h"
#include "../Players/Player.h"

#include "../Players/PlayerController.h"
#include "../Players/SpecsController.h"
#include "../Background/BackgroundController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Render/VFXAnimationController.h"
#include "../Input/InputController.h"
#include "../Input/SpecialMovesController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Collisions/AttackRegisterController.h"
#include "../Collisions/GeneralHitStopController.h"
#include "../Collisions/AttackSpecsController.h"
#include "../Cam/CamController.h"

#include "../Fighter_0_States/F0_Idle.h"

namespace RB::Updaters
{
	class GameplayUpdater : public iUpdaterObj
	{
	public:
		GameplayUpdater() = default;
		~GameplayUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}