#include "SpecialMovesController.h"

namespace RB::Input
{
	SpecialMovesController::~SpecialMovesController()
	{
		_ClearSequences(RB::Players::PlayerID::PLAYER_1);
		_ClearSequences(RB::Players::PlayerID::PLAYER_2);
	}

	void SpecialMovesController::Init()
	{
		_vecP1_Sequences.push_back(new RB::Input::Sequences::P0_Seq_Hadouken(RB::Input::SpecialMoveType::P0_HADOUKEN, { PlayerInput::MOVE_DOWN, PlayerInput::MOVE_DOWN_RIGHT, PlayerInput::MOVE_RIGHT, PlayerInput::ATTACK_WEAK_PUNCH }));

		_vecP2_Sequences.push_back(new RB::Input::Sequences::P0_Seq_Hadouken(RB::Input::SpecialMoveType::P0_HADOUKEN, { PlayerInput::MOVE_DOWN, PlayerInput::MOVE_DOWN_RIGHT, PlayerInput::MOVE_RIGHT, PlayerInput::ATTACK_WEAK_PUNCH }));
	}

	void SpecialMovesController::OnUpdate()
	{

	}

	void SpecialMovesController::OnFixedUpdate()
	{

	}

	SpecialMoveType SpecialMovesController::GetSpecialMove(RB::Players::PlayerID playerID)
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

	/// <summary>
	/// make sure to delete state after use
	/// </summary>
	RB::States::iState* SpecialMovesController::GetNewState(RB::Input::SpecialMoveType specialMoveType)
	{
		if (specialMoveType == RB::Input::SpecialMoveType::P0_HADOUKEN)
		{
			return new RB::PlayerStates::Aku::P0_Hadouken();
		}

		return nullptr;
	}

	void SpecialMovesController::_ClearSequences(RB::Players::PlayerID playerID)
	{
		std::vector<iSpecialMoveSequence*>& vec = _GetSequence(playerID);

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vec.clear();
	}

	std::vector<iSpecialMoveSequence*>& SpecialMovesController::_GetSequence(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_Sequences;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_Sequences;
		}

		return _vecNoSequences;
	}
}
