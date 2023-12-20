#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "Player.h"

#include "BackgroundController.h"
#include "SpriteDataController.h"
#include "InputController.h"
#include "SpecialMovesController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "SpecsController.h"
#include "AttackRegisterController.h"
#include "HurtBoxDataController.h"
#include "HitBoxDataController.h"
#include "GeneralHitStopController.h"
#include "VFXAnimationController.h"

#include "P0_Idle.h"

namespace RB::Updaters
{
	class GameplayUpdater : public iUpdaterObj
	{
	public:
		GameplayUpdater();
		~GameplayUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}