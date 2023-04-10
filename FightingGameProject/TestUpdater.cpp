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

		RB::Controllers::GameplayControllers::FindAll();
	}

	void TestUpdater::OnUpdate()
	{
		RB::Controllers::ControllerGroup::UpdateAll();

		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}

	void TestUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerGroup::FixedUpdateAll();
	}
}