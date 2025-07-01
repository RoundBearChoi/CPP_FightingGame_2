#pragma once

#include <vector>

#include "PlayerInput.h"
#include "SpecialMoveType.h"
#include "P0_Seq_Hadouken.h"

#include "iSpecialMoveSequence.h"
#include "iSpecialMovesController.h"

#include "../Players/PlayerID.h"
#include "../Fighter_0_States/F0_Hadouken.h"

#include "../States/iState.h"

namespace RB::Input
{
	class SpecialMovesController : public iSpecialMovesController
	{
	public:
		SpecialMovesController() = default;
		~SpecialMovesController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
		Input::SpecialMoveType GetSpecialMove(Players::PlayerID playerID) override;
		States::iState* GetNewState(Input::SpecialMoveType specialMoveType) override;

	private:
		void _ClearSequences(Players::PlayerID playerID);
		std::vector<iSpecialMoveSequence*>& _GetSequence(Players::PlayerID playerID);

		std::vector<iSpecialMoveSequence*> _vecP1_Sequences;
		std::vector<iSpecialMoveSequence*> _vecP2_Sequences;
		std::vector<iSpecialMoveSequence*> _vecNoSequences;
	};
}
