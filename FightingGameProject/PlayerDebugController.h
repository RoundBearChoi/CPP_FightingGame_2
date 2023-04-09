#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "iPlayerDebugController.h"
#include "iPlayer.h"
#include "GameplayControllers.h"

namespace RB::PlayerDebug
{
	class PlayerDebugController : public iPlayerDebugController
	{
	public:
		PlayerDebugController();
		~PlayerDebugController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void DrawXOnPlayer(RB::Players::iPlayer* player);

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}