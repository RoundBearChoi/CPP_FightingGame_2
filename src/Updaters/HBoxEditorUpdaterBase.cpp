#include "HBoxEditorUpdaterBase.h"

namespace RB::Updaters
{
	HBoxEditorUpdaterBase::~HBoxEditorUpdaterBase()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void HBoxEditorUpdaterBase::Init()
	{
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		playerController->Init();

		//RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());
		Sprites::SpriteType spriteType = RB::Sprites::LoadSpriteType(_settingsPath);

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Dummy(spriteType));
		p0->SetPosition(RB::Vector2{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);


		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;
		playerAnimationController->Init();


		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);

		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;
		playerBoxDataController->Init();

		//RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		//RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());

		if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			//RB::Controllers::ControllerBase::AddController<RB::HBox::TargetBoxDataController>(new RB::HBox::TargetBoxDataController(_specsPath));
			AddController(new HBox::TargetBoxDataController(_specsPath), Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER);

			auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
			
			targetBoxDataController->Init();
		}
		else if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			//RB::Controllers::ControllerBase::AddController<RB::HBox::AttackBoxDataController>(new RB::HBox::AttackBoxDataController(_specsPath));
			AddController(new HBox::AttackBoxDataController(_specsPath), Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER);

			auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

			attackBoxDataController->Init();
		}

		HBox::HBMenuController* menuController = RB::Controllers::ControllerBase::AddController<RB::HBox::HBMenuController>(new RB::HBox::HBMenuController());
		menuController->SetPageTitle(_pageTitle);
		
		Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>(new RB::HBox::HBoxEditController(_boxType));

		Render::PlayerDebugController* playerDebugController = RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());
		
		
		//RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;
		inputController->Init();



		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.0f);
	}

	void HBoxEditorUpdaterBase::OnUpdate()
	{
		_UpdateControllers();

		RB::Controllers::ControllerBase::UpdateAll();
	}

	void HBoxEditorUpdaterBase::OnFixedUpdate()
	{
		_FixedUpdateControllers();

		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}