#include "HBoxEditorUpdaterBase.h"

namespace RB::Updaters
{
	HBoxEditorUpdaterBase::~HBoxEditorUpdaterBase()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void HBoxEditorUpdaterBase::Init()
	{
		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
		AddController(new HBox::HBoxEditController(_boxType), Controllers::ControllerType::HBOX_EDIT_CONTROLLER);

		if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			AddController(new HBox::TargetBoxDataController(_specsPath), Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER);
		}
		else if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			AddController(new HBox::AttackBoxDataController(_specsPath), Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER);
		}

		auto playerController = static_cast<Players::iPlayerController*>(AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER));
		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));

		playerController->Init();

		//RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());
		Sprites::SpriteType spriteType = RB::Sprites::LoadSpriteType(_settingsPath);

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Dummy(spriteType));
		p0->SetPosition(RB::Vector2{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		HBox::HBMenuController* menuController = RB::Controllers::ControllerBase::AddController<RB::HBox::HBMenuController>(new RB::HBox::HBMenuController());
		menuController->SetPageTitle(_pageTitle);
		
		//Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>(new RB::HBox::HBoxEditController(_boxType));

		camController->SetZoom(1.0f);

		InitAllControllers();
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