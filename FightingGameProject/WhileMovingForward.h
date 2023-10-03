#pragma once
#include "StateComponentBase.h"
#include "MoveForward.h"
#include "MoveBack.h"
#include "P0_Idle.h"
#include "P0_MoveBack.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingForward : public RB::States::StateComponentBase
	{
	public:
		WhileMovingForward() = default;
		~WhileMovingForward() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveForward _moveForward;
		MoveBack _moveBack;
		bool _keepMoving = false;
		bool _bMoveBack = false;
	};
}