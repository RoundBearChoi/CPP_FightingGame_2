#include "PlayerState.h"

namespace RB::PlayerStates
{
	std::vector<PlayerState*> PlayerState::allPlayerStates;

	PlayerState* PlayerState::GetPlayerState(RB::Players::PlayerID playerID)
	{
		for (auto i = allPlayerStates.begin(); i != allPlayerStates.end(); i++)
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

	void PlayerState::EraseAll()
	{
		auto it = allPlayerStates.begin();

		while (it != allPlayerStates.end())
		{
			RB::PlayerStates::PlayerState* playerState = (*it);

			it = allPlayerStates.erase(it);

			delete playerState;
			playerState = nullptr;
		}

		allPlayerStates.clear();
	}

	PlayerState::PlayerState()
	{
		allPlayerStates.push_back(this);
	}

	PlayerState::~PlayerState()
	{
		//delete state components
		for (auto i = _vecStateComponents.begin(); i != _vecStateComponents.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		_vecStateComponents.clear();

		//remove self from current player states
		for (auto i = allPlayerStates.begin(); i != allPlayerStates.end(); i++)
		{
			if ((*i)->GetStateID() == _stateCreationID)
			{
				allPlayerStates.erase(i);
				break;
			}
		}
	}

	/// <summary>
	/// delete my previous states (states that are not part of the queues)
	/// </summary>
	void PlayerState::ErasePreviousStates()
	{
		auto it = allPlayerStates.begin();

		while(it != allPlayerStates.end())
		{
			unsigned int stateMachineID = (*it)->GetStateMachineID();

			// same player
			if (stateMachineID == _stateMachineID)
			{
				// different state
				if ((*it)->GetStateID() != _stateCreationID)
				{
					// not in component
					if (ContainsState_Recursive((*it)->GetStateID()) == false)
					{
						RB::PlayerStates::PlayerState* playerState = (*it);

						it = allPlayerStates.erase(it);

						delete playerState;

						continue;
					}
				}
			}

			it++;
		}
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

	//bool PlayerState::_OtherPlayerHasState(unsigned int stateID)
	//{
	//	RB::Players::iPlayer* player = GetPlayer();
	//
	//	if (player != nullptr)
	//	{
	//		RB::Players::iPlayer* otherPlayer = RB::Players::iPlayerController::instance->GetOtherPlayer(player);
	//
	//		if (otherPlayer != nullptr)
	//		{
	//			bool otherPlayerHasState = otherPlayer->GetStateMachine()->GetCurrentState()->ContainsState(_stateCreationID);
	//
	//			if (otherPlayerHasState)
	//			{
	//				return true;
	//			}
	//		}
	//	}
	//
	//	return false;
	//}
}