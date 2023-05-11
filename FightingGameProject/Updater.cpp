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
		//delete previous updater obj
		if (_updaterObj != nullptr)
		{
			delete _updaterObj;

			_updaterObj = nullptr;
		}

		//set new updater obj
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