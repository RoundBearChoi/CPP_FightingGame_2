#include "TestUpdater.h"

namespace RB::Updaters
{
	TestUpdater::TestUpdater()
	{
		std::cout << "constructing TestUpdater" << std::endl;
	}

	TestUpdater::~TestUpdater()
	{
		std::cout << "destroying TestUpdater" << std::endl;
	}

	void TestUpdater::Init()
	{
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Input::InputController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Players::PlayerController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::PlayerDebug::PlayerDebugController()));
		RB::Controllers::ControllerGroup::AddController((RB::Controllers::iController*)(new RB::Cam::GameCamController()));

		RB::Controllers::GameplayControllers::FindAll();
	}

	void TestUpdater::OnUpdate()
	{
		RB::Controllers::ControllerGroup::UpdateAll();
	}

	void TestUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerGroup::FixedUpdateAll();
	}
}