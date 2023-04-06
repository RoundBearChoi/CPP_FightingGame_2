#pragma once
#include <iostream>
#include "iEntityController.h"
#include "iController.h"

using namespace std;
using namespace RB::Controllers;

namespace RB::Entities
{
	class EntityController : iController, iEntityController
	{
	public:
		EntityController();
		~EntityController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}