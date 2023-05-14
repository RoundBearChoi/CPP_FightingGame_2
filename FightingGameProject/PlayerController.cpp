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
		RB::Players::iPlayer* p1 = new RB::Players::Player();
		RB::Players::iPlayer* p2 = new RB::Players::Player();

		_vecPlayers.reserve(2);

		_vecPlayers.push_back(p1);
		_vecPlayers.push_back(p2);

		p1->Init(PlayerID::PLAYER_1, new RB::P0_States::P0_Start());
		p2->Init(PlayerID::PLAYER_2, new RB::P0_States::P0_Start());

		p1->SetPosition(olc::vi2d{ -150, 0 });
		p2->SetPosition(olc::vi2d{ 150, 0 });

		p1->SetOtherPlayer(p2);
		p2->SetOtherPlayer(p1);
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
}