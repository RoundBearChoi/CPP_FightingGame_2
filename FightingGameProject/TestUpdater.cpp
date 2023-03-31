#include "TestUpdater.h"

namespace RB::Engine
{
	TestUpdater::TestUpdater()
	{
		std::cout << "creating TestUpdater" << std::endl;
	}

	TestUpdater::~TestUpdater()
	{
		std::cout << "destroying TestUpdater" << std::endl;
	}

	void TestUpdater::Init()
	{
		std::cout << "initializing TestUpdater" << std::endl;
	}

	void TestUpdater::OnUpdate()
	{
		//std::cout << "updating TestUpdater" << std::endl;

		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}
}