#include "PlayerBoxEditorUpdater.h"

#include "../Players/PlayerController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Render/PlayerDebugController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Collisions/PlayerBoxEditController.h"
#include "../Cam/CamController.h"

namespace RB::Updaters
{
	PlayerBoxEditorUpdater::PlayerBoxEditorUpdater()
	{
		_updaterType = UPDATER_TYPE::PLAYER_BOX_EDITOR_UPDATER;
	}

	PlayerBoxEditorUpdater::~PlayerBoxEditorUpdater()
	{
		
	}

	void PlayerBoxEditorUpdater::Init()
	{
		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
		AddController(new Collisions::PlayerBoxEditController(), Controllers::ControllerType::PLAYER_BOX_EDIT_CONTROLLER);
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);
		AddController(new Cam::CamController(1.0f, true), Controllers::ControllerType::CAM_CONTROLLER);

		_InitAllControllers();
	}

	void PlayerBoxEditorUpdater::OnUpdate()
	{
		_UpdateAllControllers();
	}

	void PlayerBoxEditorUpdater::OnFixedUpdate()
	{
		_FixedUpdateAllControllers();
	}
}
