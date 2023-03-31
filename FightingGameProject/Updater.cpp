#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "TestUpdater.h"

namespace RB::Engine
{
	Updater::Updater()
	{
		std::cout << "creating Updaters" << std::endl;
	}

	Updater::~Updater()
	{
		std::cout << "destroying Updaters" << std::endl;

		delete _updaterObj;
	}

	void Updater::Init()
	{
		std::cout << "initializing Updaters" << std::endl;

		_updaterObj = new TestUpdater();

		_updaterObj->Init();
	}

	void Updater::OnUpdate()
	{
		_updaterObj->OnUpdate();
	}
}