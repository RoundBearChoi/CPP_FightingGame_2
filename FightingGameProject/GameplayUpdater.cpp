#include "GameplayUpdater.h"

#include "iController.h"

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
#include "HurtBoxDataController.h"
#include "HitBoxDataController.h"
#include "AttackRegisterController.h"
#include "GeneralHitStopController.h"
#include "VFXAnimationController.h"

#include "Player.h"

#include "P0_Idle.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		//std::cout << std::endl;
		//std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		//std::cout << std::endl;
		//std::cout << "destructing GameplayUpdater" << std::endl;

		RB::Controllers::ControllerBase::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		//render background first
		RB::Controllers::ControllerBase::AddController<RB::Background::BackgroundController>((new RB::Background::BackgroundController()));

		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		RB::Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::Aku::P0_Idle(), olc::vi2d{-150, 0}, RB::Players::PlayerID::PLAYER_1);
		RB::Players::iPlayer* p1 = playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::Aku::P0_Idle(), olc::vi2d{150, 0}, RB::Players::PlayerID::PLAYER_2);

		p0->SetPosition(olc::vi2d{ -150, 0 });
		p1->SetPosition(olc::vi2d{ 150, 0 });

		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p1->SetCharacterType(RB::Players::CharacterType::AKU);

		RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>((playerController));
		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerDebugController>((new RB::Render::PlayerDebugController()));
		RB::Controllers::ControllerBase::AddController<RB::Render::PlayerAnimationController>((new RB::Render::PlayerAnimationController()));
		RB::Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxDataController>((new RB::Collisions::PlayerBoxDataController()));
		RB::Controllers::ControllerBase::AddController<RB::Players::Specs::SpecsController>((new RB::Players::Specs::SpecsController()));

		RB::Controllers::ControllerBase::AddController<RB::Sprites::SpriteDataController>((new RB::Sprites::SpriteDataController()));
		RB::Controllers::ControllerBase::AddController<RB::Input::InputController>((new RB::Input::InputController()));
		RB::Controllers::ControllerBase::AddController<RB::Input::SpecialMovesController>((new RB::Input::SpecialMovesController()));
		RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>((new RB::Cam::CamController()));

		RB::Controllers::ControllerBase::AddController<RB::HBox::HurtBoxDataController>((new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController<RB::HBox::HitBoxDataController>((new RB::HBox::HitBoxDataController("HitBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController<RB::Collisions::AttackRegisterController>((new RB::Collisions::AttackRegisterController()));

		RB::Controllers::ControllerBase::AddController<RB::Collisions::GeneralHitStopController>((new RB::Collisions::GeneralHitStopController()));
		RB::Controllers::ControllerBase::AddController<RB::Render::VFXAnimationController>((new RB::Render::VFXAnimationController()));

		RB::Cam::iCamController::instance->AllowManualControl(false);
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

