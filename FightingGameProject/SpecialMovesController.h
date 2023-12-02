#pragma once

#include "iSpecialMovesController.h"

namespace RB::Input
{
	class SpecialMovesController : public iSpecialMovesController
	{
	public:
		SpecialMovesController();
		~SpecialMovesController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}