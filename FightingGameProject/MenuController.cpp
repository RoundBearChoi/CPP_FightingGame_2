#include "MenuController.h"

namespace RB::HBE::Menu
{
    void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 60 }, "[ , ] : prev/next sprite", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp , PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "INS : create box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "DEL : delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "O , P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "Q : enlarge box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 200 }, "E : shrink box", olc::WHITE);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 240 }, "ENTER : save data", olc::WHITE);
	}

	void MenuController::OnFixedUpdate()
	{

	}
}