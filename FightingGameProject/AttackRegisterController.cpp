#include "AttackRegisterController.h"

#include "SpriteType.h"

#include "AttackSpecs.h"
#include "P0_Wince.h"

#include "iAttackSpecsController.h"
#include "iVFXAnimationController.h"
#include "iGeneralHitStopController.h"

namespace RB::Collisions
{
	void AttackRegisterController::Init()
	{

	}

	void AttackRegisterController::OnUpdate()
	{

	}

	void AttackRegisterController::OnFixedUpdate()
	{

	}

	void AttackRegisterController::RegisterAttack(AttackRegister reg)
	{
		RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(RB::Sprites::SpriteType::vfx_hiteffect_0, reg.collisionPoint);

		const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(reg.attackerSpriteType);

		reg.target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::Aku::P0_Wince());

		if (RB::Collisions::iGeneralHitStopController::Get() != nullptr)
		{
			RB::Collisions::iGeneralHitStopController::Get()->AddSkipFrames(3);
		}
	}
}