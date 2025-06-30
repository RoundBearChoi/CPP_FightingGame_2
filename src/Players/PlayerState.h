#pragma once

#include <vector>
#include <iostream>

#include "iPlayer.h"

#include "iPlayerController.h"

#include "../States/StateBase.h"
#include "../Sprites/SpriteType.h"

#include "../Collisions/iPlayerBoxDataController.h"
#include "../Render/iPlayerAnimationController.h"

namespace RB::Players
{
	class PlayerState : public States::StateBase
	{
	public:
		static std::vector<PlayerState*> allPlayerStates;
		static PlayerState* GetPlayerState(Players::PlayerID playerID);
		static void EraseAll();

	public:
		PlayerState();
		~PlayerState() override;
		
		void LogStateEnter() override;
		void ErasePreviousStates() override;

	public:
		Players::iPlayer* GetPlayer();
		Sprites::SpriteType GetSpriteType();
		void AutoUpdatePlayerBox();

	protected:
		Sprites::SpriteType _spriteType = Sprites::SpriteType::NONE;
	};
}
