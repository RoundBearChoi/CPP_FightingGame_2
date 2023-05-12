#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iUpdaterObj.h"
#include "iUpdaterObj.h"
#include "ActiveControllers.h"
#include "InputController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "CamController.h"
#include "PlayerAnimationController.h"


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