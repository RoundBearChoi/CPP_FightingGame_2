#include "TargetBoxEditorUpdater.h"

#include "InputController.h"
#include "SpriteDataController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "HBMenuController.h"
#include "TargetBoxDataController.h"
#include "AttackBoxDataController.h"
#include "HBoxEditController.h"

#include "Player.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	TargetBoxEditorUpdater::~TargetBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}

	void TargetBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::PlayerStates::Aku::P0_Dummy(RB::Sprites::SpriteType::aku_idle));
		p0->SetPosition(olc::vf2d{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>(new RB::Sprites::SpriteDataController());
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());

		RB::Controllers::ControllerBase::AddController<RB::HBox::HBMenuController>(new RB::HBox::HBMenuController());
		RB::Controllers::ControllerBase::AddController<RB::HBox::TargetBoxDataController>(new RB::HBox::TargetBoxDataController("TargetBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>(new RB::HBox::HBoxEditController(RB::HBox::HBoxType::TARGET_BOX));

		RB::Render::PlayerDebugController* playerDebugController = RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());

		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.75f);
	}

	void TargetBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void TargetBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}