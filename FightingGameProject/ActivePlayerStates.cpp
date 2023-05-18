#include "ActivePlayerStates.h"

namespace RB::PlayerStates
{
	void ActivePlayerStates::OnEnd()
	{
		//states are deleted by state machine
		_vecPlayerStates.clear();
	}

	void ActivePlayerStates::AddPlayerState(PlayerState* playerState)
	{
		_vecPlayerStates.push_back(playerState);
	}

	void ActivePlayerStates::RemovePlayerState(PlayerState* playerState)
	{
		for (size_t i = 0; i < _vecPlayerStates.size(); i++)
		{
			if (_vecPlayerStates[i] == playerState)
			{
				_vecPlayerStates.erase(_vecPlayerStates.begin() + i);

				return;
			}
		}
	}

	PlayerState* ActivePlayerStates::GetPlayerState(RB::Players::PlayerID playerID)
	{
		for (size_t i = 0; i < _vecPlayerStates.size(); i++)
		{
			if (_vecPlayerStates[i]->GetPlayerID() == playerID)
			{
				return _vecPlayerStates[i];
			}
		}

		return nullptr;
	}
}