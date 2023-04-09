#pragma once
#include <vector>
#include "iPlayerDebugController.h"
#include "iPlayer.h"
#include "GameplayControllers.h"

using namespace std;
using namespace RB::Players;

namespace RB::PlayerDebug
{
	class PlayerDebugController : public iPlayerDebugController
	{
	private:
		vector<iPlayer*> _vecPlayers;

	public:
		PlayerDebugController();
		~PlayerDebugController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void DrawXOnPlayer(iPlayer* player);
	};
}