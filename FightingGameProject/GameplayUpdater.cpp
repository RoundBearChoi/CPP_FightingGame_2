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

		RB::Controllers::ActiveControllers::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		RB::Controllers::ActiveControllers::Init();

		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Players::PlayerController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::ActiveControllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::ActiveControllers::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::ActiveControllers::FixedUpdateAll();
	}
}