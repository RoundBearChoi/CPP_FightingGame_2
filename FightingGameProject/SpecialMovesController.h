#pragma once

#include <vector>

#include "iSpecialMovesController.h"
#include "iSpecialMoveSequence.h"

#include "SpecialMoveSequence.h"

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

	private:
		void _ClearAllSequences();

		std::vector<iSpecialMoveSequence*> _vecSequences;
	};
}