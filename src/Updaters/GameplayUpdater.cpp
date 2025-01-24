#include "GameplayUpdater.h"
#include "GameplayUpdaterSetup.h"

namespace RB::Updaters
{
	GameplayUpdater::~GameplayUpdater()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void GameplayUpdater::Init()
	{
		GameplayUpdaterSetup setup(this);

		RB::Background::iBackgroundController* backgroundController = GET_BACKGROUND_CONTROLLER;

		backgroundController->Init();

		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

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

		Render::iPlayerDebugController* playerDebugController = GET_PLAYER_DEBUG_CONTROLLER;

		playerDebugController->Init();

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		playerAnimationController->Init();

		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;

		playerBoxDataController->Init();

		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		specsController->Init();

		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		inputController->Init();

		//RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());
		//RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		//RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());
		//RB::Controllers::ControllerBase::AddController<RB::Players::SpecsController>((new RB::Players::SpecsController()));

		//RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());
		RB::Controllers::ControllerBase::AddController<RB::Input::SpecialMovesController>(new RB::Input::SpecialMovesController());

		RB::Controllers::ControllerBase::AddController<RB::HBox::TargetBoxDataController>(new RB::HBox::TargetBoxDataController("../resource/TargetBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::HBox::AttackBoxDataController>(new RB::HBox::AttackBoxDataController("../resource/AttackBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::Collisions::AttackRegisterController>(new RB::Collisions::AttackRegisterController());

		RB::Controllers::ControllerBase::AddController<RB::Collisions::GeneralHitStopController>(new RB::Collisions::GeneralHitStopController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::AttackSpecsController>(new RB::Collisions::AttackSpecsController());
		RB::Controllers::ControllerBase::AddController<RB::Render::VFXAnimationController>(new RB::Render::VFXAnimationController());

		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->AllowManualControl(false);
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