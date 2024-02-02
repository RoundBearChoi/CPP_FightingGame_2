#include "GameplayUpdater.h"

#include "BackgroundController.h"
#include "PlayerController.h"
#include "PlayerDebugController.h"
#include "PlayerAnimationController.h"
#include "PlayerBoxDataController.h"
#include "SpecsController.h"
#include "SpriteDataController.h"
#include "InputController.h"
#include "SpecialMovesController.h"
#include "CamController.h"
#include "TargetBoxDataController.h"
#include "HitBoxDataController.h"
#include "AttackRegisterController.h"
#include "GeneralHitStopController.h"
#include "VFXAnimationController.h"

#include "Player.h"

#include "P0_Idle.h"

namespace RB::Updaters
{
	GameplayUpdater::~GameplayUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		//render background first
		RB::Controllers::ControllerBase::AddController<RB::Background::BackgroundController>(new RB::Background::BackgroundController());

		RB::Players::PlayerController* playerController = RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());
		RB::Players::iPlayer* p1 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::PlayerStates::Aku::P0_Idle());
		p0->SetPosition(olc::vf2d{ -150.0f, 0.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(false);

		p1->Init(RB::Players::PlayerID::PLAYER_2, new RB::PlayerStates::Aku::P0_Idle());
		p1->SetPosition(olc::vf2d{ 150.0f, 0.0f });
		p1->SetCharacterType(RB::Players::CharacterType::AKU);
		p1->SetManualAnimationUpdate(false);

		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>(new RB::Render::PlayerDebugController());
		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>(new RB::Render::PlayerAnimationController());
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>(new RB::Collisions::PlayerBoxDataController());
		RB::Controllers::ControllerBase::AddController<RB::Players::Specs::SpecsController>((new RB::Players::Specs::SpecsController()));

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>(new RB::Sprites::SpriteDataController());
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>(new RB::Input::InputController());
		RB::Controllers::ControllerBase::AddController<RB::Input::SpecialMovesController>(new RB::Input::SpecialMovesController());

		RB::Controllers::ControllerBase::AddController<RB::HBox::TargetBoxDataController>(new RB::HBox::TargetBoxDataController("TargetBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HitBoxDataController>(new RB::HBox::HitBoxDataController("AttackBoxSpecs/"));
		RB::Controllers::ControllerBase::AddController<RB::Collisions::AttackRegisterController>(new RB::Collisions::AttackRegisterController());

		RB::Controllers::ControllerBase::AddController<RB::Collisions::GeneralHitStopController>(new RB::Collisions::GeneralHitStopController());
		RB::Controllers::ControllerBase::AddController<RB::Render::VFXAnimationController>(new RB::Render::VFXAnimationController());

		RB::Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->AllowManualControl(false);
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}