#pragma once
#include "iPlayerDebugController.h"

namespace RB::PlayerDebug
{
	class PlayerDebugController : public iPlayerDebugController
	{
	public:
		~PlayerDebugController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}