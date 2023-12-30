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
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Background::BackgroundController()));

		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::Aku::P0_Idle(), olc::vi2d{-150, 0}, RB::Players::PlayerID::PLAYER_1);
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::Aku::P0_Idle(), olc::vi2d{150, 0}, RB::Players::PlayerID::PLAYER_2);

		playerController->GetPlayerOnIndex(0)->SetPosition(olc::vi2d{ -150, 0 });
		playerController->GetPlayerOnIndex(1)->SetPosition(olc::vi2d{ 150, 0 });

		playerController->GetPlayerOnIndex(0)->SetCharacterType(RB::Players::CharacterType::AKU);
		playerController->GetPlayerOnIndex(1)->SetCharacterType(RB::Players::CharacterType::AKU);

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Collisions::PlayerBoxDataController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Players::Specs::SpecsController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Input::SpecialMovesController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HurtBoxDataController("HurtBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::HBox::HitBoxDataController("HitBoxSpecs/")));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Collisions::AttackRegisterController()));

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Collisions::GeneralHitStopController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::VFXAnimationController()));

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