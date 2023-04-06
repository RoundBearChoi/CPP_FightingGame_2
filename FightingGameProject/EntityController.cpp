#include "EntityController.h"

namespace RB::Entities
{
	EntityController::EntityController()
	{
		cout << "constructing TestUpdater" << endl;
	}

	EntityController::~EntityController()
	{
		cout << "destroying TestUpdater" << endl;
	}
}