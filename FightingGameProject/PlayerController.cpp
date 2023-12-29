#include "PlayerController.h"

#include "PlayerState.h" //erase all in the end

namespace RB::Players
{
	PlayerController::~PlayerController()
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		RB::PlayerStates::PlayerState::EraseAll();
	}

	void PlayerController::Init()
	{

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
			(*i)->OnFixedUpdate();
		}
	}

	void PlayerController::AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID)
	{
		_vecPlayers.reserve(2);

		iPlayer* p = player;

		//gotta add first because Init involves OnEnter -> StateComponents -> player search
		_vecPlayers.push_back(p);

		p->Init(playerID, firstState);
		p->SetPosition(startPos);
	}

	iPlayer* PlayerController::GetPlayerOnIndex(unsigned int index)
	{
		if (index < _vecPlayers.size())
		{
			return _vecPlayers[index];
		}

		return nullptr;
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