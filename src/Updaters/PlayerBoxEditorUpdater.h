#pragma once

#include "iUpdaterObj.h"

#include "../Vector2.h"
#include "../Players/Player.h"

#include "../PlayerController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Cam/CamController.h"
#include "../Render/PlayerDebugController.h"
#include "../InputController.h"
#include "../Collisions/PlayerBoxEditController.h"

#include "../P0_Dummy.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public iUpdaterObj
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
