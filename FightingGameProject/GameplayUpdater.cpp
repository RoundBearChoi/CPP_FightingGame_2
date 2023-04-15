#include "GameplayUpdater.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		std::cout << "destroying GameplayUpdater" << std::endl;
	}

	void GameplayUpdater::Init()
	{
		RB::Input::CurrentInputController::Init();

		RB::Cam::CurrentCam::Init();

		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Players::PlayerController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Cam::GameCamController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::GameplayControllers::FindAll();
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::ControllerGroup::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerGroup::FixedUpdateAll();
	}
}