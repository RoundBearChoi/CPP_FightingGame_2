#pragma once

#include <vector>

#include "PlayerInput.h"
#include "SpecialMoveType.h"
#include "P0_Seq_Hadouken.h"

#include "iSpecialMoveSequence.h"
#include "iSpecialMovesController.h"

#include "../Players/PlayerID.h"
#include "../Fighter_0_States/P0_Hadouken.h"

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
		RB::Input::SpecialMoveType GetSpecialMove(RB::Players::PlayerID playerID) override;
		RB::States::iState* GetNewState(RB::Input::SpecialMoveType specialMoveType) override;

	private:
		void _ClearSequences(RB::Players::PlayerID playerID);
		std::vector<iSpecialMoveSequence*>& _GetSequence(RB::Players::PlayerID playerID);

		std::vector<iSpecialMoveSequence*> _vecP1_Sequences;
		std::vector<iSpecialMoveSequence*> _vecP2_Sequences;
		std::vector<iSpecialMoveSequence*> _vecNoSequences;
	};
}
