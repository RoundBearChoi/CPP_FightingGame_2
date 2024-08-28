#include "AttackRegisterController.h"
#include "AttackRegister.h"
#include "CollisionType.h"

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
		ShowHitVFX(reg);
		ShowHitLocation(reg);

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

	void AttackRegisterController::ShowHitVFX(const AttackRegister& attackRegister)
	{
		RB::Render::iAnimationObj* hitVFX = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
			RB::Sprites::SpriteType::vfx_hiteffect_0,
			attackRegister.collisionPoint,
			attackRegister.targetIsOnRightSide);
		
		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			8, 
			RB::Render::RenderScaleMultiplierType::LINEAR, 
			1.5f));

		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			20, 
			RB::Render::RenderScaleMultiplierType::LINEAR, 
			0.8f));

		hitVFX->AddRenderRotationObj(new Render::RenderRotationObj(
			20,
			8.0f));

		hitVFX->AddRenderTransparency(new Render::RenderTransparencyObj(
			7,
			1.0f));

		hitVFX->AddRenderTransparency(new Render::RenderTransparencyObj(
			12,
			0.0f));
	}

	void AttackRegisterController::ShowHitLocation(const AttackRegister& attackRegister)
	{
		RB::Render::iAnimationObj* hitVFX_word = nullptr;

		if (attackRegister.collisionType == CollisionType::HEAD)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_head,
				attackRegister.collisionPoint,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::BODY)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_body,
				attackRegister.collisionPoint,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::LEGS)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_leg,
				attackRegister.collisionPoint,
				true);
		}

		if (hitVFX_word == nullptr)
		{
			return;
		}
			
		hitVFX_word->AddRenderTransparency(new Render::RenderTransparencyObj(
			25,
			0.0f));
	}
}
