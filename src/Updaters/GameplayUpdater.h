#pragma once

#include "iUpdaterObj.h"

#include "../Vector2.h"
#include "../Players/Player.h"

#include "../PlayerController.h"
#include "../Background/BackgroundController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../SpecsController.h"
#include "../InputController.h"
#include "../SpecialMovesController.h"
#include "../Cam/CamController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../Collisions/AttackRegisterController.h"
#include "../Collisions/GeneralHitStopController.h"
#include "../Collisions/AttackSpecsController.h"
#include "../Render/VFXAnimationController.h"

#include "../P0_Idle.h"

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
