#include "PlayerState.h"

namespace RB::PlayerStates
{
	std::vector<PlayerState*> PlayerState::currentPlayerStates;

	PlayerState* PlayerState::GetPlayerState(RB::Players::PlayerID playerID)
	{
		for (auto i = currentPlayerStates.begin(); i != currentPlayerStates.end(); i++)
		{
			RB::Players::iPlayer* owner = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID((*i)->GetStateMachineID());

			if (owner != nullptr)
			{
				if (playerID == owner->GetPlayerID())
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	PlayerState::PlayerState()
	{
		currentPlayerStates.push_back(this);
	}

	PlayerState::~PlayerState()
	{
		//remove self from current player states
		for (auto i = currentPlayerStates.begin(); i != currentPlayerStates.end(); i++)
		{
			if ((*i)->GetCreationID() == _stateCreationID)
			{
				currentPlayerStates.erase(i);
				break;
			}
		}

		//delete state components
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
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
}