#include "PlayerBoxEditorUpdater.h"

#include "../Players/PlayerController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Render/PlayerDebugController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Collisions/PlayerBoxEditController.h"
#include "../Cam/CamController.h"
#include "../Input/InputController.h"

#include "../Fighter_0_States/F0_Dummy.h"

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
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
		AddController(new Collisions::PlayerBoxEditController(), Controllers::ControllerType::PLAYER_BOX_EDIT_CONTROLLER);
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);

		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));
		
		camController->SetZoom(1.0f);

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
