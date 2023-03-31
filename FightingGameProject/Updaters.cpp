#include "olcPixelGameEngine.h"
#include "Updaters.h"
#include "TestUpdater.h"

namespace RB::Engine
{
	Updaters::Updaters()
	{
		std::cout << "creating Updaters" << std::endl;
	}

	Updaters::~Updaters()
	{
		std::cout << "destroying Updaters" << std::endl;

		delete _updaterObj;
	}

	void Updaters::Init()
	{
		std::cout << "initializing Updaters" << std::endl;

		_updaterObj = new TestUpdater();

		_updaterObj->Init();
	}

	void Updaters::OnUpdate()
	{
		_updaterObj->OnUpdate();
	}
}