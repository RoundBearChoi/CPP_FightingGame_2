#include "HitBoxEditorUpdater.h"

#include "Player.h"
#include "P0_Dummy.h"

#include "InputController.h"
#include "SpriteDataController.h"
#include "CamController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "MenuController.h"
#include "HurtBoxDataController.h"
#include "HitBoxDataController.h"
#include "HBoxEditController.h"

namespace RB::Updaters
{
	HitBoxEditorUpdater::HitBoxEditorUpdater()
	{

	}

	HitBoxEditorUpdater::~HitBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}

	void HitBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();

		playerController->AddPlayer(new RB::Players::Player,
			new RB::PlayerStates::P0_Dummy(RB::Sprites::SpriteEnum::fighter_0_jab), //set starting sprite enum
			olc::vi2d{ 0, 0 },
			RB::Players::PlayerID::PLAYER_1);

		playerController->SetManualAnimationUpdate(RB::Players::PlayerID::PLAYER_1, true);

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::MenuController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HitBoxDataController("HitBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HBoxEditController(RB::HBox::HBoxType::HIT_BOX)));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));

		RB::Cam::iCamController::instance->SetZoom(1.75f);
	}

	void HitBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void HitBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}