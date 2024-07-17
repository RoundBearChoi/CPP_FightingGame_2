#include "HBoxEditorUpdaterBase.h"

#include "Vector2.h"

#include "InputController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "HBMenuController.h"
#include "TargetBoxDataController.h"
#include "AttackBoxDataController.h"
#include "HBoxEditController.h"
#include "SpriteTypeLoader.h"

#include "Player.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	HBoxEditorUpdaterBase::~HBoxEditorUpdaterBase()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void HBoxEditorUpdaterBase::Init()
	{
		RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());
		RB::Sprites::SpriteType spriteType = RB::Sprites::LoadSpriteType(_settingsPath);

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::PlayerStates::Aku::P0_Dummy(spriteType));
		p0->SetPosition(RB::Vector2{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());

		if (_boxType == RB::HBox::HBoxType::TARGET_BOX)
		{
			RB::Controllers::ControllerBase::AddController<RB::HBox::TargetBoxDataController>(new RB::HBox::TargetBoxDataController(_specsPath));
		}
		else if (_boxType == RB::HBox::HBoxType::ATTACK_BOX)
		{
			RB::Controllers::ControllerBase::AddController<RB::HBox::AttackBoxDataController>(new RB::HBox::AttackBoxDataController(_specsPath));
		}

		RB::HBox::HBMenuController* menuController = RB::Controllers::ControllerBase::AddController<RB::HBox::HBMenuController>(new RB::HBox::HBMenuController());
		menuController->SetPageTitle(_pageTitle);
		
		RB::Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>(new RB::HBox::HBoxEditController(_boxType));

		RB::Render::PlayerDebugController* playerDebugController = RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());
		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.0f);
	}

	void HBoxEditorUpdaterBase::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void HBoxEditorUpdaterBase::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}
