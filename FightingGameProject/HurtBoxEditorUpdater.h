#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "ActiveControllers.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "InputController.h"
#include "CamController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"
#include "Player.h"

namespace RB::Updaters
{
	class HurtBoxEditorUpdater : public iUpdaterObj
	{
		public:
			HurtBoxEditorUpdater();
			~HurtBoxEditorUpdater() override;

			void Init();
			void OnUpdate();
			void OnFixedUpdate();
	};
}