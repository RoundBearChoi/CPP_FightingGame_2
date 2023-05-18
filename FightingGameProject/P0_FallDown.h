#pragma once
#include <iostream>
#include "StateBase.h"
#include "PlayerID.h"
#include "PlayerController.h"
#include "iPlayer.h"

#include "P0_Idle.h"

namespace RB::P0_States
{
	class P0_FallDown : public RB::States::StateBase
	{
	public:
		P0_FallDown() = default;
		~P0_FallDown() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
	};
}