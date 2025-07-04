#include "SpecialMoveSequenceBase.h"

namespace RB::Input
{
	SpecialMoveSequenceBase::~SpecialMoveSequenceBase()
	{

	}

	bool SpecialMoveSequenceBase::IsMatching(Players::PLAYER_TYPE playerID)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;
		Input::iInputController* inputController = GET_INPUT_CONTROLLER;

		if (playerController == nullptr)
		{
			return false;
		}

		if (inputController == nullptr)
		{
			return false;
		}

		unsigned int seqIndex = 0;
		std::vector<bool> vecCorrect;
		std::vector<Input::iInputObj*> vecCorrectObjs;
		Players::iPlayer* p = playerController->GetPlayer(playerID);

		if (p->GetHP() <= 0)
		{
			return false;
		}

		if (p->IsWincing())
		{
			return false;
		}

		const std::vector<Input::PlayerInput>& sequence = _GetSequence(p->IsFacingRight());

		const auto& vec = inputController->GetVecInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if ((*i) == nullptr)
			{
				continue;
			}

			if (!(*i)->IsUsedAsAttack())
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
				(*i)->SetUsedAsAttack(true);
			}

			return true;
		}

		return false;
	}

	Input::SpecialMoveType SpecialMoveSequenceBase::GetSpecialMoveType()
	{
		return _specialMoveType;
	}

	void SpecialMoveSequenceBase::_SetSequence(SpecialMoveType specialMoveType, const std::vector<Input::PlayerInput>& vec)
	{
		_specialMoveType = specialMoveType;

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			_vecSequence.push_back((*i));
		}
	}

	void SpecialMoveSequenceBase::_SetSequenceForRightSide(const std::vector<Input::PlayerInput>& vec)
	{
		for (auto i = vec.begin(); i != vec.end(); ++i)
    	{
        	int value = i->_to_integral();
        	
			if (value == Input::PlayerInput::MOVE_LEFT)
        	{
            	_vecSequenceFromRightSide.push_back(Input::PlayerInput::MOVE_RIGHT);
        	}
        	else if (value == Input::PlayerInput::MOVE_DOWN_LEFT)
        	{
            	_vecSequenceFromRightSide.push_back(Input::PlayerInput::MOVE_DOWN_RIGHT);
        	}
        	else if (value == Input::PlayerInput::MOVE_RIGHT)
        	{
            	_vecSequenceFromRightSide.push_back(Input::PlayerInput::MOVE_LEFT);
        	}
        	else if (value == Input::PlayerInput::MOVE_DOWN_RIGHT)
        	{
            	_vecSequenceFromRightSide.push_back(Input::PlayerInput::MOVE_DOWN_LEFT);
        	}
        	else
        	{
            	_vecSequenceFromRightSide.push_back(*i);
        	}
    	}
	}

	const std::vector<Input::PlayerInput>& SpecialMoveSequenceBase::_GetSequence(bool playerIsFacingRight)
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
