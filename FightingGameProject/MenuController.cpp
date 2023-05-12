#include "MenuController.h"

namespace RB::HBE::Menu
{
    void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);
	}

	void MenuController::OnFixedUpdate()
	{

	}
}