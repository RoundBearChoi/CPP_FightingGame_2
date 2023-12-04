#include "HurtBoxEditorUpdater.h"

#include "Player.h"
#include "P0_Dummy.h"

#include "ActiveControllers.h"
#include "InputController.h"
#include "SpriteDataController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"
#include "HBoxEditController.h"

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

		playerController->AddPlayer(new RB::Players::Player,
			new RB::PlayerStates::P0_Dummy(RB::Sprites::SpriteEnum::fighter_0_idle), //set starting sprite enum
			olc::vi2d{ 0, 0 },
			RB::Players::PlayerID::PLAYER_1);

		playerController->SetManualAnimationUpdate(RB::Players::PlayerID::PLAYER_1, true);

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::MenuController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HBoxEditController(RB::HBox::HBoxType::HURT_BOX)));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));

		RB::Cam::CAM_CONTROLLER->SetZoom(1.75f);
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