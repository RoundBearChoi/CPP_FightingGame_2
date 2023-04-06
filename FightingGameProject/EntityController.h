#pragma once
#include <iostream>
#include "iEntityController.h"

using namespace std;

namespace RB::Entities
{
	class EntityController : iEntityController
	{
	public:
		EntityController();
		~EntityController();
	};
}