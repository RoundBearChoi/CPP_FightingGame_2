#include "SpecialMovesController.h"

namespace RB::Input
{
	SpecialMovesController::SpecialMovesController()
	{
		SetHash(typeid(*this));

		SPECIAL_MOVES_CONTROLLER = this;
	}

	SpecialMovesController::~SpecialMovesController()
	{
		SPECIAL_MOVES_CONTROLLER = nullptr;
	}

	void SpecialMovesController::Init()
	{

	}

	void SpecialMovesController::OnUpdate()
	{

	}

	void SpecialMovesController::OnFixedUpdate()
	{

	}
}