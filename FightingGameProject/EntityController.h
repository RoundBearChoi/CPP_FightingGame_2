#pragma once
#include <iostream>
#include "iEntityController.h"
#include "ControllerBase.h"

using namespace std;
using namespace RB::Controllers;

namespace RB::Entities
{
	class EntityController : ControllerBase, iEntityController
	{
	public:
		EntityController();
		~EntityController();

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}