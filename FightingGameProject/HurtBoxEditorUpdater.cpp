#include "HurtBoxEditorUpdater.h"

#include "iController.h"

#include "InputController.h"
#include "SpriteDataController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"
#include "HitBoxDataController.h"
#include "HBoxEditController.h"

#include "Player.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	HurtBoxEditorUpdater::HurtBoxEditorUpdater()
	{

	}

	HurtBoxEditorUpdater::~HurtBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}

	void HurtBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();

		RB::Players::iPlayer* dummyP = playerController->AddPlayer(new RB::Players::Player,
			new RB::PlayerStates::Aku::P0_Dummy(RB::Sprites::SpriteEnum::aku_idle), //set starting sprite enum
			olc::vi2d{ 0, 0 },
			RB::Players::PlayerID::PLAYER_1);

		dummyP->SetPosition(olc::vi2d{ 50, 100 });
		dummyP->SetManualAnimationUpdate(true);

		RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>((playerController));
		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>((new RB::Render::PlayerAnimationController()));
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>((new RB::Collisions::PlayerBoxDataController()));

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>((new RB::Sprites::SpriteDataController()));
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>((new RB::Input::InputController()));
		RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>((new RB::Cam::CamController()));

		RB::Controllers::ControllerBase::AddController<RB::HBox::MenuController>((new RB::HBox::MenuController()));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HurtBoxDataController>((new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HBoxEditController>((new RB::HBox::HBoxEditController(RB::HBox::HBoxType::HURT_BOX)));

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>((new RB::Render::PlayerDebugController()));

		RB::Cam::iCamController::instance->SetZoom(1.75f);
	}

	void HurtBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void HurtBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}

