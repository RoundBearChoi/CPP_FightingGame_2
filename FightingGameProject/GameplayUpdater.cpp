#include "GameplayUpdater.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		std::cout << std::endl;
		std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		std::cout << std::endl;
		std::cout << "destructing GameplayUpdater" << std::endl;

		RB::Controllers::ControllerBase::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		//render background first
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Background::BackgroundController()));

		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::P0_Start(), olc::vi2d{-150, 0}, RB::Players::PlayerID::PLAYER_1);
		playerController->AddPlayer(new RB::Players::Player(), new RB::PlayerStates::P0_Start(), olc::vi2d{150, 0}, RB::Players::PlayerID::PLAYER_2);
		playerController->SetCharacterType(RB::Players::PlayerID::PLAYER_1, RB::Players::CharacterType::PLAYER_0);
		playerController->SetCharacterType(RB::Players::PlayerID::PLAYER_2, RB::Players::CharacterType::PLAYER_0);

		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));
		RB::Controllers::ControllerBase::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

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