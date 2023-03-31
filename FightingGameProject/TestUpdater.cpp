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
	}
}