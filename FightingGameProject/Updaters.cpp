#include "Updaters.h"
#include "olcPixelGameEngine.h"

namespace RB::Engine
{
	Updaters::Updaters()
	{
		std::cout << "creating updater" << std::endl;
	}
	Updaters::~Updaters()
	{
		std::cout << "destroying updater" << std::endl;
	}

	void Updaters::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}
}