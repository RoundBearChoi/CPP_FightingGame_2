#include "GameplayUpdater.h"

#include "../Background/BackgroundController.h"
#include "../Players/SpecsController.h"
#include "../Players/PlayerController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Render/VFXAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Collisions/AttackRegisterController.h"
#include "../Collisions/HitStopController.h"
#include "../Collisions/AttackSpecsController.h"
#include "../Input/InputController.h"
#include "../Input/SpecialMovesController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../Cam/CamController.h"
#include "../Logger/LogController.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		_updaterType = UPDATER_TYPE::GAMEPLAY_UPDATER;
	}

	GameplayUpdater::~GameplayUpdater()
	{

	}

	void GameplayUpdater::Init()
	{
        AddController(new Background::BackgroundController(), Controllers::ControllerType::BACKGROUND_CONTROLLER);
        AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
        AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
        AddController(new Collisions::PlayerBoxDataController, Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
        AddController(new Players::SpecsController(), Controllers::ControllerType::SPECS_CONTROLLER);
        AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Input::SpecialMovesController(), Controllers::ControllerType::SPECIAL_MOVES_CONTROLLER);
		AddController(new HBox::TargetBoxDataController("../resource/TargetBoxSpecs/"), Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER);
		AddController(new HBox::AttackBoxDataController("../resource/AttackBoxSpecs/"), Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER);
		AddController(new Collisions::AttackRegisterController(), Controllers::ControllerType::ATTACK_REGISTER_CONTROLLER);
		AddController(new Collisions::HitStopController(), Controllers::ControllerType::HITSTOP_CONTROLLER);
		AddController(new Collisions::AttackSpecsController(), Controllers::ControllerType::ATTACK_SPECS_CONTROLLER);
		AddController(new Render::VFXAnimationController(), Controllers::ControllerType::VFX_ANIMATION_CONTROLLER);
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);
		
		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));

		camController->AllowManualControl(false);

		_InitAllControllers();
	}

	void GameplayUpdater::OnUpdate()
	{
		_UpdateAllControllers();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		_FixedUpdateAllControllers();
	}
}
