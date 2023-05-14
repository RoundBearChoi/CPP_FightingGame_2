#include "PlayerController.h"

namespace RB::Players
{
	PlayerController::PlayerController()
	{
		std::cout << "constructing PlayerController" << std::endl;

		SetHash(typeid(*this));
	}

	PlayerController::~PlayerController()
	{
		std::cout << "destroying PlayerController" << std::endl;

		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			delete _vecPlayers[i];
		}
	}

	void PlayerController::Init()
	{

	}

	void PlayerController::OnUpdate()
	{
		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			_vecPlayers[i]->OnUpdate();
		}
	}

	void PlayerController::OnFixedUpdate()
	{
		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			_vecPlayers[i]->OnFixedUpdate();
		}
	}

	void PlayerController::AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID, bool manualAnimationUpdate)
	{
		_vecPlayers.reserve(2);

		iPlayer* p = player;

		p->Init(playerID, firstState);
		p->SetPosition(startPos);
		p->SetManualAnimationUpdate(manualAnimationUpdate);

		_vecPlayers.push_back(p);
	}

	iPlayer* PlayerController::GetPlayerOnIndex(size_t index)
	{
		if (index < _vecPlayers.size())
		{
			return _vecPlayers[index];
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetPlayerOnID(PlayerID id)
	{
		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			if (_vecPlayers[i]->GetPlayerID() == id)
			{
				return _vecPlayers[i];
			}
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetPlayerOnStateMachineID(size_t id)
	{
		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			if (_vecPlayers[i]->GetStateMachineID() == id)
			{
				return _vecPlayers[i];
			}
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetOtherPlayer(iPlayer* currentPlayer)
	{
		for (size_t i = 0; i < _vecPlayers.size(); i++)
		{
			if (_vecPlayers[i]->GetPlayerID() != currentPlayer->GetPlayerID())
			{
				return _vecPlayers[i];
			}
		}

		return nullptr;
	}
}