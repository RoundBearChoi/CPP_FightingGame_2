#include "GameplayUpdater.h"

namespace RB::Updaters
{
	GameplayUpdater::GameplayUpdater()
	{
		std::cout << "constructing GameplayUpdater" << std::endl;
	}

	GameplayUpdater::~GameplayUpdater()
	{
		std::cout << "destructing GameplayUpdater" << std::endl;

		RB::Controllers::Controllers::OnEnd();
	}

	void GameplayUpdater::Init()
	{
		RB::Controllers::Controllers::Init();
		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::Cam::CamController()));
		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::Players::PlayerController()));
		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::Controllers::AddController((RB::Controllers::iController*)(new RB::Render::PlayerAnimationController()));
	}

	void GameplayUpdater::OnUpdate()
	{
		RB::Controllers::Controllers::UpdateAll();
	}

	void GameplayUpdater::OnFixedUpdate()
	{
		RB::Controllers::Controllers::FixedUpdateAll();
	}
}