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
	}

	void HurtBoxEditorUpdater::Init()
	{
		RB::Controllers::ActiveControllers::Init();

		RB::Players::iPlayer* player = new RB::Players::Player();
		player->SetManualAnimationUpdate(true);

		RB::Players::PlayerController* playerController = new RB::Players::PlayerController();
		playerController->AddPlayer(player, new RB::P0_States::P0_Idle_Dummy(), olc::vi2d{ 0, 0 }, RB::Players::PlayerID::PLAYER_1);

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(playerController));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HBE::Menu::MenuController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::HurtBox::HurtBoxDataController()));
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