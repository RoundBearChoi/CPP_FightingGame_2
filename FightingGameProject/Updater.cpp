#include "olcPixelGameEngine.h"
#include "Updater.h"
#include "GameplayUpdater.h"

namespace RB::Updaters
{
	Updater::Updater()
	{
		std::cout << "constructing Updater" << std::endl;
	}

	Updater::~Updater()
	{
		std::cout << "destroying Updater" << std::endl;

		delete _updaterObj;
	}

	void Updater::Init()
	{
		_updaterObj = new GameplayUpdater();

		_updaterObj->Init();
	}

	void Updater::OnUpdate()
	{
		_updaterObj->OnUpdate();
	}

	void Updater::OnFixedUpdate()
	{
		_updaterObj->OnFixedUpdate();
	}
}