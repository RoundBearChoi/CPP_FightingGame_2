#include "AttackRegisterController.h"

#include "SpriteType.h"

#include "AttackSpecs.h"
#include "RenderScaleMultiplierObj.h"

#include "P0_Wince.h" //temp
#include "P0_Strong_Wince.h" //temp

#include "iAttackSpecsController.h"
#include "iAnimationObj.h"
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
		RB::Render::iAnimationObj* he0 = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(RB::Sprites::SpriteType::vfx_hiteffect_0, reg.collisionPoint);
		he0->AddMultiplierObj({ 50, RB::Render::RenderScaleMultiplierType::LINEAR, 1.0f });

		const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(reg.attackerSpriteType);

		if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::STRONG)
		{
			reg.target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::Aku::P0_Strong_Wince());
		}
		else if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::WEAK)
		{
			reg.target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::Aku::P0_Wince());
		}

		if (RB::Collisions::iGeneralHitStopController::Get() != nullptr)
		{
			RB::Collisions::iGeneralHitStopController::Get()->AddSkipFrames(attackSpecs.mHitStop);
		}
	}
}