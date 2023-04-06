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

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}