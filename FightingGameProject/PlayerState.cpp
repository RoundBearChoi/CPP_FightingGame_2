#include "PlayerState.h"

namespace RB::PlayerStates
{
	std::vector<PlayerState*> PlayerState::currentPlayerStates;
	size_t PlayerState::playerStateCreationCount = 0;

	PlayerState* PlayerState::GetPlayerState(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < currentPlayerStates.size(); i++)
		{
			RB::Players::iPlayer* owner = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(currentPlayerStates[i]->GetStateMachineID());

			if (owner != nullptr)
			{
				if (playerID == owner->GetPlayerID())
				{
					return currentPlayerStates[i];
				}
			}
		}

		return nullptr;
	}

	PlayerState::PlayerState()
	{
		playerStateCreationCount++;
		_creationID = playerStateCreationCount;

		currentPlayerStates.push_back(this);
	}

	PlayerState::~PlayerState()
	{
		for (int32_t i = currentPlayerStates.size() - 1; i >= 0; i--)
		{
			if (_creationID == currentPlayerStates[i]->GetCreationID())
			{
				currentPlayerStates.erase(currentPlayerStates.begin() + i);
				break;
			}
		}	

		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
			_vecStateComponents[i] = nullptr;
		}

		_vecStateComponents.clear();
	}

	RB::Players::iPlayer* PlayerState::GetPlayer()
	{
		return RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_stateMachineID);

		return nullptr;
	}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
	}

	size_t PlayerState::GetCreationID()
	{
		return _creationID;
	}
}