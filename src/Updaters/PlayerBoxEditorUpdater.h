#pragma once

#include "iUpdater.h"

#include "../Vector2.h"
#include "../Players/Player.h"

#include "../Players/PlayerController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Cam/CamController.h"
#include "../Render/PlayerDebugController.h"
#include "../Input/InputController.h"
#include "../Collisions/PlayerBoxEditController.h"

#include "../Fighter_0_States/F0_Dummy.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public iUpdater
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}