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
		_vecSequences.push_back(new SpecialMoveSequenceBase());
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