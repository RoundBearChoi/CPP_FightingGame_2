#pragma once
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "PlayerID.h"
#include "PlayerState.h"
#include "ActivePlayerStates.h"

#include "iPlayerController.h"
#include "iHitBoxDataController.h"
#include "iHurtBoxDataController.h"

namespace RB::PlayerStateComponents
{
	class DetectHit : public RB::States::StateComponentBase
	{
	public:
		DetectHit() = default;
		~DetectHit() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}