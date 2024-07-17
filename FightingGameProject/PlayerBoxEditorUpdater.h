#pragma once

#include "Vector2.h"
#include "Player.h"

#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "CamController.h"
#include "PlayerDebugController.h"
#include "InputController.h"
#include "PlayerBoxEditController.h"

#include "iUpdaterObj.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public iUpdaterObj
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}
