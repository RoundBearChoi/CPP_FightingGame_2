#include "PlayerState.h"

namespace RB::PlayerStates
{
	std::vector<PlayerState*> PlayerState::currentPlayerStates;
	size_t PlayerState::playerStateCreationCount = 0;

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
				currentPlayerStates[i] = nullptr;
				currentPlayerStates.erase(currentPlayerStates.begin() + i);
				break;
			}
		}	

		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}

		_vecStateComponents.clear();
	}

	void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;

		_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);
	}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
	}

	RB::Players::PlayerID PlayerState::GetPlayerID()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return RB::Players::PlayerID::NONE;
		}
				
		if (_ownerPlayer == nullptr)
		{
			std::cout << "no owner player" << std::endl;
		}

		return _ownerPlayer->GetPlayerID();
	}

	size_t PlayerState::GetCreationID()
	{
		return _creationID;
	}
}