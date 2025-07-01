#include "SpecialMovesController.h"

namespace RB::Input
{
	SpecialMovesController::~SpecialMovesController()
	{
		_ClearSequences(Players::PlayerID::PLAYER_1);
		_ClearSequences(Players::PlayerID::PLAYER_2);
	}

	void SpecialMovesController::Init()
	{
		//INIT_CONTROLLER
		
		_vecP1_Sequences.push_back(new Input::Sequences::P0_Seq_Hadouken(Input::SpecialMoveType::P0_HADOUKEN, { PlayerInput::MOVE_DOWN, PlayerInput::MOVE_DOWN_RIGHT, PlayerInput::MOVE_RIGHT, PlayerInput::ATTACK_WEAK_PUNCH }));

		_vecP2_Sequences.push_back(new Input::Sequences::P0_Seq_Hadouken(Input::SpecialMoveType::P0_HADOUKEN, { PlayerInput::MOVE_DOWN, PlayerInput::MOVE_DOWN_RIGHT, PlayerInput::MOVE_RIGHT, PlayerInput::ATTACK_WEAK_PUNCH }));
	}

	void SpecialMovesController::OnUpdate()
	{

	}

	void SpecialMovesController::OnFixedUpdate()
	{

	}

	SpecialMoveType SpecialMovesController::GetSpecialMove(Players::PlayerID playerID)
	{
		const std::vector<iSpecialMoveSequence*>& vec = _GetSequence(playerID);

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if ((*i)->IsMatching(playerID))
			{
				return (*i)->GetSpecialMoveType();
			}
		}

		return SpecialMoveType::NONE;
	}

	// make sure to delete state after use
	States::iState* SpecialMovesController::GetNewState(Input::SpecialMoveType specialMoveType)
	{
		if (specialMoveType == Input::SpecialMoveType::P0_HADOUKEN)
		{
			return new Fighter_0_States::F0_Hadouken();
		}

		return nullptr;
	}

	void SpecialMovesController::_ClearSequences(Players::PlayerID playerID)
	{
		std::vector<iSpecialMoveSequence*>& vec = _GetSequence(playerID);

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vec.clear();
	}

	std::vector<iSpecialMoveSequence*>& SpecialMovesController::_GetSequence(Players::PlayerID playerID)
	{
		if (playerID._value == Players::PlayerID::PLAYER_1)
		{
			return _vecP1_Sequences;
		}
		else if (playerID._value == Players::PlayerID::PLAYER_2)
		{
			return _vecP2_Sequences;
		}

		return _vecNoSequences;
	}
}
