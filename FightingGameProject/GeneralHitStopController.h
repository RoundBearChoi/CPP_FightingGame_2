#pragma once
#include "iGeneralHitStopController.h"

namespace RB::Collisions
{
	class GeneralHitStopController : public iGeneralHitStopController
	{
	public:
		GeneralHitStopController();
		~GeneralHitStopController() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}