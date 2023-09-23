#include "HitBoxEditorUpdater.h"

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
#include "HurtBoxEditController.h"

namespace RB::Updaters
{
	HitBoxEditorUpdater::HitBoxEditorUpdater()
	{

	}

	HitBoxEditorUpdater::~HitBoxEditorUpdater()
	{
		RB::Controllers::ActiveControllers::OnEnd();
		RB::States::ActiveStateMachines::OnEnd();
	}

	void HitBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();

		playerController->AddPlayer(new RB::Players::Player,
			new RB::PlayerStates::P0_Dummy(RB::Sprites::SpriteEnum::fighter_0_idle), //set starting sprite enum
			olc::vi2d{ 0, 0 },
			RB::Players::PlayerID::PLAYER_1);

		playerController->SetManualAnimationUpdate(RB::Players::PlayerID::PLAYER_1, true);

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBox::MenuController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBox::HurtBoxEditController()));

		RB::Cam::CAM_CONTROLLER->SetZoom(1.75f);
	}

	void HitBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ActiveControllers::UpdateAll();
	}

	void HitBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ActiveControllers::FixedUpdateAll();
	}
}