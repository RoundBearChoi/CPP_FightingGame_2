#include "PlayerBoxEditorUpdater.h"

//#include "ControllerBase.h"

#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "CamController.h"
#include "PlayerDebugController.h"
#include "SpriteDataController.h"
#include "InputController.h"

#include "Player.h"

#include "P0_Dummy.h"

namespace RB::Updaters
{
	PlayerBoxEditorUpdater::~PlayerBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}
	void PlayerBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::PlayerStates::Aku::P0_Dummy(RB::Sprites::SpriteEnum::aku_crouch));
		p0->SetPosition(olc::vf2d{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>(new RB::Sprites::SpriteDataController());
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());

		RB::Render::PlayerDebugController* playerDebugController = RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());

		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.75f);
	}

	void PlayerBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void PlayerBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}