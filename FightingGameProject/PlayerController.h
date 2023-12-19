#pragma once
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
		void AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID) override;

	public:
		iPlayer* GetPlayerOnIndex(size_t index) override;
		iPlayer* GetPlayerOnID(PlayerID id) override;
		iPlayer* GetPlayerOnStateMachineID(size_t id) override;
		iPlayer* GetOtherPlayer(iPlayer* currentPlayer) override;
		void SetManualAnimationUpdate(PlayerID id, bool manual) override;

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}