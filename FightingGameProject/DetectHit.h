#pragma once
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "PlayerID.h"
#include "PlayerState.h"
#include "ActivePlayerStates.h"

#include "P0_Wince.h"

#include "iPlayerController.h"
#include "iHitBoxDataController.h"
#include "iHurtBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iAttackRegisterController.h"
#include "iGeneralHitStopController.h"

#include "LineRenderer.h"

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

	private:
		//temp debug
		olc::vf2d _col = { 0.0f, 0.0f };
		RB::Render::LineRenderer _lineRenderer;
	};
}