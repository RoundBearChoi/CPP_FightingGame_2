#include "Updater.h"
#include "olcPixelGameEngine.h"

namespace RB::Engine
{
	Updater::Updater()
	{
		std::cout << "creating updater" << std::endl;
	}
	Updater::~Updater()
	{
		std::cout << "destroying updater" << std::endl;
	}

	void Updater::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawLine(10, 10, 502, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 470, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(502, 10, 502, 470, olc::YELLOW);
	}
}