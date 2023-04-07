#pragma once
#include <iostream>
#include "iPlayerController.h"

using namespace std;

namespace RB::Players
{
	class PlayerController : public iPlayerController
	{
	public:
		PlayerController();
		~PlayerController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}