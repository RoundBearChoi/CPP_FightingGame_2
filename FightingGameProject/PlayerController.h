#pragma once
#include <iostream>
#include "iPlayerController.h"
#include "iController.h"

using namespace std;
using namespace RB::Controllers;

namespace RB::Players
{
	class PlayerController : iController, iPlayerController
	{
	public:
		PlayerController();
		~PlayerController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}