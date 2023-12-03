#pragma once
#include "ControllerBase.h"
#include "SpecialMoveType.h"
#include "PlayerID.h"
#include "iState.h"

namespace RB::Input
{
	class iSpecialMovesController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual RB::Input::SpecialMoveType GetSpecialMove(RB::Players::PlayerID playerID) = 0;
		virtual RB::States::iState* GetState(RB::Input::SpecialMoveType specialMoveType) = 0;
	};

	extern iSpecialMovesController* SPECIAL_MOVES_CONTROLLER;
}