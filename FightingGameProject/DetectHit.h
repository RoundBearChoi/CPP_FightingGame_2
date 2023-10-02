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

//temp
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
		RB::Render::LineRenderer _lineRenderer;
		RB::Collisions::AABB _tempOwnerAABB;
		RB::Collisions::AABB _tempTargetAABB;
	};
}