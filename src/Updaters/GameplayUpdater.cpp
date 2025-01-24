#include "GameplayUpdater.h"
#include "GameplayUpdaterSetup.h"

#include "../HBox/TargetBoxDataController.h"
#include "../Collisions/AttackRegisterController.h"
#include "../Cam/CamController.h"
#include "../Players/PlayerController.h"

namespace RB::Updaters
{
	GameplayUpdater::~GameplayUpdater()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void GameplayUpdater::Init()
	{
		GameplayUpdaterSetup setup(this);

		AddController(new Input::SpecialMovesController(), Controllers::ControllerType::SPECIAL_MOVES_CONTROLLER);
		AddController(new HBox::TargetBoxDataController("../resource/TargetBoxSpecs/"), Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER);
		AddController(new HBox::AttackBoxDataController("../resource/AttackBoxSpecs/"), Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER);
		AddController(new Collisions::AttackRegisterController(), Controllers::ControllerType::ATTACK_REGISTER_CONTROLLER);
		AddController(new Collisions::GeneralHitStopController(), Controllers::ControllerType::GENERAL_HITSTOP_CONTROLLER);
		AddController(new Collisions::AttackSpecsController(), Controllers::ControllerType::ATTACK_SPECS_CONTROLLER);
		AddController(new Render::VFXAnimationController(), Controllers::ControllerType::VFX_ANIMATION_CONTROLLER);

		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));
		auto playerController = static_cast<Players::iPlayerController*>(AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER));

		playerController->Init();

		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());
		RB::Players::iPlayer* p1 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Idle());
		p0->SetPosition(RB::Vector2{ -150.0f, 0.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(false);

		p1->Init(RB::Players::PlayerID::PLAYER_2, new RB::Fighter_0_States::F0_Idle());
		p1->SetPosition(RB::Vector2{ 150.0f, 0.0f });
		p1->SetCharacterType(RB::Players::CharacterType::AKU);
		p1->SetManualAnimationUpdate(false);

		camController->AllowManualControl(false);

		InitAllControllers();
	}

	void GameplayUpdater::OnUpdate()
	{
		_UpdateControllers();

		RB::Controllers::ControllerBase::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		_FixedUpdateControllers();

		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}