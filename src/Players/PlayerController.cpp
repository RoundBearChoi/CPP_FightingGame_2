#include "PlayerController.h"

#include "../Updaters/CurrentPlayground.h"

#include "../Fighter_0_States/F0_Idle.h"

namespace RB::Players
{
	PlayerController::~PlayerController()
	{
		for (auto i = _vecPlayers.begin(); i != _vecPlayers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		Players::PlayerState::EraseAll();
	}

	void PlayerController::Init()
	{
		std::cout << "init PlayerController.. " << Updaters::ptrCurrentPlayground->GetUpdater()->GetUpdaterType()._to_string() << std::endl;

		auto updaterType = Updaters::ptrCurrentPlayground->GetUpdater()->GetUpdaterType();

		if (updaterType._value == Updaters::UPDATER_TYPE::GAMEPLAY_UPDATER)
		{
			_InitOnGameplayUpdater();
		}
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
			for (auto j = Players::PlayerState::allPlayerStates.begin(); j != Players::PlayerState::allPlayerStates.end(); j++)
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

	iPlayer* PlayerController::GetPlayer(PlayerID id)
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

	void PlayerController::_InitOnGameplayUpdater()
	{
		Players::iPlayer* p0 = AddPlayer();
		Players::iPlayer* p1 = AddPlayer();

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Idle());
		p0->SetPosition(RB::Vector2{ -150.0f, 0.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(false);

		p1->Init(RB::Players::PlayerID::PLAYER_2, new RB::Fighter_0_States::F0_Idle());
		p1->SetPosition(RB::Vector2{ 150.0f, 0.0f });
		p1->SetCharacterType(RB::Players::CharacterType::AKU);
		p1->SetManualAnimationUpdate(false);
	}

	void PlayerController::_InitOnHBoxEditorUpdater()
	{
		auto p0 = AddPlayer();

	}
}
