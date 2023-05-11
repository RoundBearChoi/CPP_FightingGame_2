#include "GameplayUpdater.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		std::cout << "GameplayUpdater OnEnd" << std::endl;

		RB::Input::CurrentInputController::OnEnd();
		RB::Cam::CurrentCam::OnEnd();
		RB::Controllers::CurrentControllers::OnEnd();
		RB::Controllers::GameplayControllers::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		RB::Input::CurrentInputController::Init();

		RB::Cam::CurrentCam::Init();

		RB::Controllers::CurrentControllers::Init();
		RB::Controllers::CurrentControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::CurrentControllers::AddController((RB::Controllers::iController*)(new RB::Players::PlayerController()));
		RB::Controllers::CurrentControllers::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::CurrentControllers::AddController((RB::Controllers::iController*)(new RB::Cam::GameCamController()));
		RB::Controllers::CurrentControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));

		RB::Controllers::GameplayControllers::Init();
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::CurrentControllers::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::CurrentControllers::FixedUpdateAll();
	}
}