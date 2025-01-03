#include "AttackRegisterController.h"
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
		_ShowHitVFX(reg);
		_ShowHitLocation(reg);

		const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(reg.attackerSpriteType);

		reg.target->AddHP(-attackSpecs.mDamage);

		if (reg.targetIsCrouching)
		{
			//std::cout << std::endl;
			//std::cout << "target is crouching" << std::endl;

			reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::F0_Crouch_Weak_Wince());
		}
		else
		{
			//std::cout << std::endl;
			//std::cout << "target is NOT crouching" << std::endl;

			if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::STRONG)
			{
				if (reg.collisionType == CollisionType::HEAD)
				{
					reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::F0_Strong_Wince_High());
				}
				else if (reg.collisionType == CollisionType::BODY)
				{
					reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::F0_Strong_Wince_Mid());
				}
			}
			else if (attackSpecs.mAttackStrengthType._value == RB::Collisions::AttackStrengthType::WEAK)
			{
				reg.target->GetStateMachine()->OverrideNextState(new RB::Fighter_0_States::F0_Weak_Wince_Mid());
			}

			if (RB::Collisions::iGeneralHitStopController::Get() != nullptr)
			{
				RB::Collisions::iGeneralHitStopController::Get()->AddSkipFrames(attackSpecs.mHitStop);
			}
		}
	}

	void AttackRegisterController::_ShowHitVFX(const AttackRegister& attackRegister)
	{
		RB::Render::iAnimationObj* hitVFX = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
			RB::Sprites::SpriteType::vfx_hiteffect_0,
			attackRegister.collisionPoint,
			attackRegister.targetIsOnRightSide);
		
		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			4, 
			RB::Render::OperationType::SINE, 
			1.4f));

		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			15,
			RB::Render::OperationType::SINE, 
			0.7f));

		hitVFX->AddRenderRotationObj(new Render::RenderRotationObj(
			20,
			Render::OperationType::SINE,
			8.0f));

		hitVFX->AddRenderTransparency(new Render::RenderTransparencyObj(
			45,
			Render::OperationType::SINE,
			0.0f));
	}

	void AttackRegisterController::_ShowHitLocation(const AttackRegister& attackRegister)
	{
		RB::Render::iAnimationObj* hitVFX_word = nullptr;

		RandomGenerator randX;
		RandomGenerator randY;
		int x = randX.GetRand(10, 30);
		int y = randY.GetRand(10, 30);

		RB::Vector2 pos;

		if (!attackRegister.targetIsOnRightSide)
		{
			pos = attackRegister.collisionPoint + Vector2{-x, -y};
		}
		else
		{
			pos = attackRegister.collisionPoint + Vector2{x, -y};
		}

		if (attackRegister.collisionType == CollisionType::HEAD)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_head,
				pos,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::BODY)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_body,
				pos,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::LEGS)
		{
			hitVFX_word = RB::Render::iVFXAnimationController::Get()->InstantiateAnimation(
				RB::Sprites::SpriteType::vfx_hiteffect_leg,
				pos,
				true);
		}

		if (hitVFX_word == nullptr)
		{
			return;
		}
			
		hitVFX_word->AddRenderTransparency(new Render::RenderTransparencyObj(
			30,
			Render::OperationType::SINE,
			0.0f));

		RandomGenerator randomRot;
		int rot = randomRot.GetRand(-10, 10);

		hitVFX_word->AddRenderRotationObj(new Render::RenderRotationObj(
			35,
			RB::Render::OperationType::SINE,
			float(rot)));

		hitVFX_word->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			5,
			RB::Render::OperationType::SINE,
			1.4f));

		hitVFX_word->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			12,
			RB::Render::OperationType::SINE,
			0.6f));
	}
}