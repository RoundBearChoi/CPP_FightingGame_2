#include "GeneralHitStopController.h"

namespace RB::Collisions
{
	GeneralHitStopController::GeneralHitStopController()
	{
		SetHash(typeid(*this));

		GENERAL_HIT_STOP_CONTROLLER = this;
	}

	GeneralHitStopController::~GeneralHitStopController()
	{
		GENERAL_HIT_STOP_CONTROLLER = nullptr;
	}

	void GeneralHitStopController::Init()
	{

	}

	void GeneralHitStopController::OnUpdate()
	{

	}

	void GeneralHitStopController::OnFixedUpdate()
	{

	}
}