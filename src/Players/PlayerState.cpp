#include "PlayerState.h"

namespace RB::Players
{
	std::vector<PlayerState*> PlayerState::allPlayerStates;

	PlayerState* PlayerState::GetPlayerState(Players::PlayerID playerID)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		for (auto i = allPlayerStates.begin(); i != allPlayerStates.end(); i++)
		{
			Players::iPlayer* owner = playerController->GetPlayerOnStateMachineID((*i)->GetStateMachineID());

			if (owner != nullptr)
			{
				if (playerID._value == owner->GetPlayerID())
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
			Players::PlayerState* playerState = (*it);

			it = allPlayerStates.erase(it);

			delete playerState;
			playerState = nullptr;
		}

		allPlayerStates.clear();
	}

	PlayerState::PlayerState()
	{
		_stateType = States::STATE_TYPE::PLAYER_STATE;

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

	// delete my previous states (states that are not part of the queues)
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
						Players::PlayerState* playerState = (*it);

						it = allPlayerStates.erase(it);

						delete playerState;

						continue;
					}
				}
			}

			it++;
		}
	}

	Players::iPlayer* PlayerState::GetPlayer()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		return playerController->GetPlayerOnStateMachineID(_stateMachineID);
	}

	Sprites::SpriteType PlayerState::GetSpriteType()
	{
		return _spriteType;
	}

	void PlayerState::AutoUpdatePlayerBox()
	{
		Collisions::iPlayerBoxDataController* playerBoxDataController = GET_PLAYER_BOX_DATA_CONTROLLER;

		Players::iPlayer* player = GetPlayer();

		Players::CharacterType characterType = player->GetCharacterType();

		if (playerBoxDataController == nullptr)
		{
			return;
		}

		Collisions::LoadedPlayerBoxData* loaded = playerBoxDataController->GetLoadedData(characterType);

		if (loaded == nullptr)
		{
			return;
		}

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		Render::iAnimationObj* iAniObj = playerAnimationController->GetCurrentAnimationObj(GetPlayer()->GetPlayerID(), _spriteType);

		if (iAniObj == nullptr)
		{
			return;
		}

		unsigned int animationIndex = iAniObj->GetCurrentIndex();

		Collisions::PlayerBox* box = loaded->GetSpecs(_spriteType, animationIndex);

		if (box == nullptr)
		{
			return;
		}

		player->GetPlayerCollider()->SetPlayerBox(*box);
	}
}
