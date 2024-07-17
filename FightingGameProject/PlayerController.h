#pragma once

#include "PlayerState.h" //erase all in the end

#include "iPlayer.h"
#include "iPlayerController.h"

namespace RB::Players
{
	class PlayerController : public iPlayerController
	{
	public:
		PlayerController() = default;
		~PlayerController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		iPlayer* AddPlayer(iPlayer* player) override;

	public:
		iPlayer* GetPlayerOnIndex(unsigned int index) override;
		iPlayer* GetPlayerOnID(PlayerID id) override;
		iPlayer* GetPlayerOnStateMachineID(unsigned int id) override;
		iPlayer* GetOtherPlayer(iPlayer* currentPlayer) override;

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}
