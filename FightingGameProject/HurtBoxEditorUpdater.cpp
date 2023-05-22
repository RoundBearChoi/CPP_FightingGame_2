#include "HurtBoxEditorUpdater.h"

namespace RB::Updaters
{
	HurtBoxEditorUpdater::HurtBoxEditorUpdater()
	{
		std::cout << std::endl;
		std::cout << "constructing HurtBoxEditorUpdater" << std::endl;
	}

	HurtBoxEditorUpdater::~HurtBoxEditorUpdater()
	{
		std::cout << std::endl;
		std::cout << "destructing HurtBoxEditorUpdater" << std::endl;

		RB::Controllers::ActiveControllers::OnEnd();
		RB::States::ActiveStateMachines::OnEnd();
	}

	void HurtBoxEditorUpdater::Init()
	{
		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		playerController->AddPlayer(new RB::Players::Player, new RB::PlayerStates::P0_Dummy(), olc::vi2d{ 0, 0 }, RB::Players::PlayerID::PLAYER_1, true);

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(playerController));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerDebugController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Sprites::SpriteDataController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HurtBox::MenuController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HurtBox::HurtBoxDataController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HurtBox::HurtBoxEditController()));
	}

	void HurtBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ActiveControllers::UpdateAll();
	}

	void HurtBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ActiveControllers::FixedUpdateAll();
	}
}