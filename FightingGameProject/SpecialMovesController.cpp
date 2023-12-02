#include "SpecialMovesController.h"

namespace RB::Input
{
	SpecialMovesController::SpecialMovesController()
	{
		SetHash(typeid(*this));

		SPECIAL_MOVES_CONTROLLER = this;
	}

	SpecialMovesController::~SpecialMovesController()
	{
		_ClearAllSequences();

		SPECIAL_MOVES_CONTROLLER = nullptr;
	}

	void SpecialMovesController::Init()
	{
		RB::Input::PlayerInput p0_hadouken[4] = { PlayerInput::MOVE_DOWN, PlayerInput::MOVE_DOWN_RIGHT, PlayerInput::MOVE_RIGHT, PlayerInput::ATTACK_WEAK_PUNCH };

		_vecSequences.push_back(new RB::Input::Sequences::P0_Hadouken(RB::Input::SpecialMoveType::P0_HADOUKEN, p0_hadouken, 4));
	}

	void SpecialMovesController::OnUpdate()
	{

	}

	void SpecialMovesController::OnFixedUpdate()
	{

	}

	void SpecialMovesController::_ClearAllSequences()
	{
		for (int32_t i = _vecSequences.size() - 1; i >= 0; i--)
		{
			delete _vecSequences[i];
			_vecSequences[i] = nullptr;
		}

		_vecSequences.clear();
	}
}