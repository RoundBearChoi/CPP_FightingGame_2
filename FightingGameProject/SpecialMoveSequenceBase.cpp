#include "SpecialMoveSequenceBase.h"

namespace RB::Input
{
	SpecialMoveSequenceBase::~SpecialMoveSequenceBase()
	{

	}

	bool SpecialMoveSequenceBase::IsMatching(RB::Players::PlayerID playerID)
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return false;
		}

		if (RB::Input::iInputController::Get() == nullptr)
		{
			return false;
		}

		unsigned int seqIndex = 0;
		std::vector<bool> vecCorrect;
		std::vector<RB::Input::iInputObj*> vecCorrectObjs;
		RB::Players::iPlayer* p = RB::Players::iPlayerController::Get()->GetPlayerOnID(playerID);

		if (p->IsWincing())
		{
			return false;
		}

		const std::vector<RB::Input::PlayerInput>& sequence = _GetSequence(p->IsFacingRight());

		const auto& vec = RB::Input::iInputController::Get()->GetVecInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if ((*i) == nullptr)
			{
				continue;
			}

			if (!(*i)->IsUsedAsSpecial())
			{
				if (sequence.size() > seqIndex)
				{
					if ((*i)->GetPlayerInputType() == sequence[seqIndex])
					{
						vecCorrect.push_back(true);
						vecCorrectObjs.push_back((*i));
						seqIndex++;
					}
				}
			}
		}

		if (vecCorrect.size() == sequence.size())
		{
			for (auto i = vecCorrectObjs.begin(); i != vecCorrectObjs.end(); ++i)
			{
				(*i)->SetUsedAsSpecial(true);
			}

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

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			_vecSequence.push_back((*i));
		}
	}

	void SpecialMoveSequenceBase::_SetSequenceForRightSide(const std::vector<RB::Input::PlayerInput>& vec)
	{
		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i) == PlayerInput::MOVE_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_RIGHT);
			}
			else if ((*i) == PlayerInput::MOVE_DOWN_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_RIGHT);
			}
			else if ((*i) == PlayerInput::MOVE_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_LEFT);
			}
			else if ((*i) == PlayerInput::MOVE_DOWN_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_LEFT);
			}
			else
			{
				_vecSequenceFromRightSide.push_back((*i));
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
