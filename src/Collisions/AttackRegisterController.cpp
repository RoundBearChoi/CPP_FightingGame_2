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
			8, 
			RB::Render::RenderScaleMultiplierType::LINEAR, 
			2.55f));

		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			20, 
			RB::Render::RenderScaleMultiplierType::LINEAR, 
			0.8f));

		hitVFX->AddRenderRotationObj(new Render::RenderRotationObj(
			20,
			8.0f));

		hitVFX->AddRenderTransparency(new Render::RenderTransparent(
			7,
			1.0f));

		hitVFX->AddRenderTransparency(new Render::RenderTransparent(
			12,
			0.0f));

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
