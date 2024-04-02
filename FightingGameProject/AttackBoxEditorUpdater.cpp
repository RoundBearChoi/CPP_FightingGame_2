#include "AttackBoxEditorUpdater.h"

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
#include "SpriteTypeLoader.h"

#include "Player.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	AttackBoxEditorUpdater::~AttackBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}

	void AttackBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());

		SpriteTypeLoader spLoader;
		RB::Sprites::SpriteType spriteType = spLoader.LoadSpriteType("EditorSettings/AttackBoxSettings.editorSettings");

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::PlayerStates::Aku::P0_Dummy(RB::Sprites::SpriteType::aku_jab));
		p0->SetPosition(olc::vf2d{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>(new RB::Sprites::SpriteDataController());
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());

		RB::Controllers::ControllerBase::AddController<RB::HBox::HBMenuController>(new RB::HBox::HBMenuController());
		RB::Controllers::ControllerBase::AddController<RB::HBox::AttackBoxDataController>(new RB::HBox::AttackBoxDataController("AttackBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>(new RB::HBox::HBoxEditController(RB::HBox::HBoxType::ATTACK_BOX));

		RB::Render::PlayerDebugController* playerDebugController = RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());

		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.75f);
	}

	void AttackBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void AttackBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}