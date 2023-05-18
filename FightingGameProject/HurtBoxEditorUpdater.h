#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "Player.h"

#include "ActiveControllers.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "InputController.h"
#include "CamController.h"
#include "SpriteDataController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"

#include "ActiveStateMachines.h"

#include "P0_Dummy.h"

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