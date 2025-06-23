#include "PlayerController.h"

namespace RB::Players
{
	PlayerController::~PlayerController()
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		RB::Players::PlayerState::EraseAll();
	}

	void PlayerController::Init()
	{
		//INIT_CONTROLLER
	}

	void PlayerController::OnUpdate()
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			(*i)->OnUpdate();
		}
	}

	void PlayerController::OnFixedUpdate()
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			for (auto j = RB::Players::PlayerState::allPlayerStates.begin(); j != RB::Players::PlayerState::allPlayerStates.end(); j++)
			{
				if ((*j)->GetStateMachineID() != 0)
				{
					if ((*j)->GetStateID() == (*i)->GetStateMachine()->GetCurrentState()->GetStateID())
					{
						(*j)->AutoUpdatePlayerBox();
					}
				}
			}

			(*i)->OnFixedUpdate();
		}
	}

	iPlayer* PlayerController::AddPlayer()
	{
		iPlayer* p = new Player();

		_vecPlayers.push_back(p);

		return p;
	}

	iPlayer* PlayerController::GetPlayerOnID(PlayerID id)
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			if ((*i)->GetPlayerID() == id)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetPlayerOnStateMachineID(unsigned int id)
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			if ((*i)->GetStateMachineID() == id)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetOtherPlayer(iPlayer* currentPlayer)
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			if ((*i)->GetPlayerID() != currentPlayer->GetPlayerID())
			{
				return (*i);
			}
		}

		return nullptr;
	}
}
