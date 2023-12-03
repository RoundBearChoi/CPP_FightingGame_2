#include "SpecialMoveSequenceBase.h"

namespace RB::Input
{
	SpecialMoveSequenceBase::~SpecialMoveSequenceBase()
	{

	}

	bool SpecialMoveSequenceBase::IsMatching(RB::Players::PlayerID playerID)
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return false;
		}

		if (RB::Input::INPUT_CONTROLLER == nullptr)
		{
			return false;
		}

		//size_t inputCount = ;
		size_t seqIndex = 0;
		std::vector<bool> vecCorrectInput;

		RB::Players::iPlayer* p = RB::Players::PLAYER_CONTROLLER->GetPlayerOnID(playerID);
		const std::vector<RB::Input::PlayerInput>& vec = _GetSequence(p->IsFacingRight());

		for (size_t i = 0; i < RB::Input::INPUT_CONTROLLER->GetTotalInputCount(playerID); i++)
		{
			RB::Input::iInputObj* obj = RB::Input::INPUT_CONTROLLER->GetInputByIndex(playerID, i);

			if (obj->GetPlayerInputType() == vec[seqIndex])
			{
				vecCorrectInput.push_back(true);
				seqIndex++;
			}
		}

		if (vecCorrectInput.size() == vec.size())
		{
			return true;
		}

		return false;
	}

	RB::Input::SpecialMoveType SpecialMoveSequenceBase::GetSpecialMoveType()
	{
		return _specialMoveType;
	}

	void SpecialMoveSequenceBase::_SetSequence(SpecialMoveType specialMoveType, const std::vector<RB::Input::PlayerInput>& vec)
	{
		_specialMoveType = specialMoveType;

		for (size_t i = 0; i < vec.size(); i++)
		{
			_vecSequence.push_back(vec[i]);
		}
	}

	void SpecialMoveSequenceBase::_SetSequenceForRightSide(const std::vector<RB::Input::PlayerInput>& vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i] == PlayerInput::MOVE_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_RIGHT);
			}
			else if (vec[i] == PlayerInput::MOVE_DOWN_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_RIGHT);
			}
			else if (vec[i] == PlayerInput::MOVE_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_LEFT);
			}
			else if (vec[i] == PlayerInput::MOVE_DOWN_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_LEFT);
			}
			else
			{
				_vecSequenceFromRightSide.push_back(vec[i]);
			}
		}
	}

	const std::vector<RB::Input::PlayerInput>& SpecialMoveSequenceBase::_GetSequence(bool playerIsFacingRight)
	{
		if (playerIsFacingRight)
		{
			return _vecSequence;
		}
		else
		{
			return _vecSequenceFromRightSide;
		}
	}
}