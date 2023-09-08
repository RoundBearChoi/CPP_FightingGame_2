#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "Player.h"
#include "P0_Dummy.h"

#include "ActiveControllers.h"
#include "InputController.h"
#include "SpriteDataController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"
#include "HurtBoxEditController.h"

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