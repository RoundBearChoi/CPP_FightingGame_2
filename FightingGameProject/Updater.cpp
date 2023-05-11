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

	void Updater::SetUpdaterObj(iUpdaterObj* updaterObj)
	{
		_updaterObj = updaterObj;

		if (_updaterObj != nullptr)
		{
			_updaterObjExists = true;

			_updaterObj->Init();
		}
	}

	void Updater::Init()
	{
		SetUpdaterObj(new GameplayUpdater());
	}

	void Updater::OnUpdate()
	{
		if (_updaterObjExists)
		{
			_updaterObj->OnUpdate();
		}
	}

	void Updater::OnFixedUpdate()
	{
		if (_updaterObjExists)
		{
			_updaterObj->OnFixedUpdate();
		}
	}
}