#include "TestUpdater.h"

namespace RB::Engine
{
	TestUpdater::TestUpdater()
	{
		cout << "constructing TestUpdater" << endl;
	}

	TestUpdater::~TestUpdater()
	{
		cout << "destroying TestUpdater" << endl;
	}

	void TestUpdater::Init()
	{
		ControllerGroup::AddController((iController*)(new EntityController()));
	}

	void TestUpdater::OnUpdate()
	{
		ControllerGroup::UpdateAll();

		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}

	void TestUpdater::OnFixedUpdate()
	{
		ControllerGroup::FixedUpdateAll();
	}
}