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
		_updaterObj = new TestUpdater();
	}

	void Updaters::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}
}