#include "GameplayUpdater.h"

#include "../Background/BackgroundController.h"
#include "../Players/SpecsController.h"
#include "../Players/PlayerController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Render/VFXAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Collisions/AttackRegisterController.h"
#include "../Collisions/GeneralHitStopController.h"
#include "../Collisions/AttackSpecsController.h"
#include "../Input/InputController.h"
#include "../Input/SpecialMovesController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../Cam/CamController.h"

#include "../Fighter_0_States/F0_Idle.h"

namespace RB::Updaters
{
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
		AddController(new Collisions::GeneralHitStopController(), Controllers::ControllerType::GENERAL_HITSTOP_CONTROLLER);
		AddController(new Collisions::AttackSpecsController(), Controllers::ControllerType::ATTACK_SPECS_CONTROLLER);
		AddController(new Render::VFXAnimationController(), Controllers::ControllerType::VFX_ANIMATION_CONTROLLER);

		auto playerController = static_cast<Players::iPlayerController*>(AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER));
		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));

		Players::iPlayer* p0 = playerController->AddPlayer();
		Players::iPlayer* p1 = playerController->AddPlayer();

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Idle());
		p0->SetPosition(RB::Vector2{ -150.0f, 0.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(false);

		p1->Init(RB::Players::PlayerID::PLAYER_2, new RB::Fighter_0_States::F0_Idle());
		p1->SetPosition(RB::Vector2{ 150.0f, 0.0f });
		p1->SetCharacterType(RB::Players::CharacterType::AKU);
		p1->SetManualAnimationUpdate(false);

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