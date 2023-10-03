#pragma once
#include "StateComponentBase.h"
#include "MoveBackDetector.h"
#include "MoveForward.h"
#include "P0_Idle.h"
#include "P0_MoveForward.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStateComponents
{
	class WhileMovingBack : public RB::States::StateComponentBase
	{
	public:
		WhileMovingBack() = default;
		~WhileMovingBack() override {};

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		MoveBack _moveBackDetector;
		MoveForward _moveForward;
		bool _bKeepMoving = false;
		bool _bMoveForward = false;
	};
}