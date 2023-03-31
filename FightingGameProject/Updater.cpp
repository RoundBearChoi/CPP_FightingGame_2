#include "Updater.h"
#include "olcPixelGameEngine.h"

namespace RB::Engine
{
	UpdaterBase::UpdaterBase()
	{
		std::cout << "creating updater" << std::endl;
	}
	UpdaterBase::~UpdaterBase()
	{
		std::cout << "destroying updater" << std::endl;
	}

	void UpdaterBase::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawLine(10, 10, 400, 10, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 10, 10, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(400, 10, 400, 300, olc::YELLOW);
		olc::Renderer::ptrPGE->DrawLine(10, 300, 400, 300, olc::YELLOW);
	}
}