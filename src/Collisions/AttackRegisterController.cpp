#include "AttackRegisterController.h"

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
		RB::Render::iAnimationObj* hitVFX = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
			RB::Sprites::SpriteType::vfx_hiteffect_0,
			reg.collisionPoint,
			reg.targetIsOnRightSide);
		
		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			10, 
			RB::Render::RenderScaleMultiplierType::LINEAR, 
			2.2f));
		//hitVFX->AddRenderScaleMultiplierObj({ 10, RB::Render::RenderScaleMultiplierType::LINEAR, 2.2f });
		//hitVFX->AddRenderScaleMultiplierObj({ 30, RB::Render::RenderScaleMultiplierType::LINEAR, 0.95f });
		//hitVFX->AddRenderRotationObj({ 15, 10.0f });
		//hitVFX->AddRenderRotationObj({ 10, -19.0f });

		const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(reg.attackerSpriteType);

		if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::STRONG)
		{
			reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::F0_Strong_Wince());
		}
		else if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::WEAK)
		{
			reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::P0_Wince());
		}

		if (RB::Collisions::iGeneralHitStopController::Get() != nullptr)
		{
			RB::Collisions::iGeneralHitStopController::Get()->AddSkipFrames(attackSpecs.mHitStop);
		}
	}
}
