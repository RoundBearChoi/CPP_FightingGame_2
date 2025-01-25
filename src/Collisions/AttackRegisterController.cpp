#include "AttackRegisterController.h"

//temp
//#include "../Fighter_0_States/F0_Kneel.h"
#include "../Updaters/CurrentPlayground.h"
#include "iAttackSpecsController.h"
#include "iHitStopController.h"

namespace RB::Collisions
{
	void AttackRegisterController::Init()
	{
		INIT_CONTROLLER
	}

	void AttackRegisterController::OnUpdate()
	{

	}

	void AttackRegisterController::OnFixedUpdate()
	{

	}

	bool AttackRegisterController::RegisterAttack(AttackRegister reg)
	{
		auto hitstopController = GET_HITSTOP_CONTROLLER;
		auto attackSpecsController = GET_ATTACK_SPECS_CONTROLLER;

		_ShowHitVFX(reg);
		_ShowHitLocation(reg);

		const Collisions::AttackSpecs& attackSpecs = attackSpecsController->GetAttackSpecs(reg.attackerSpriteType);

		reg.target->AddHP(-attackSpecs.mDamage);

		if (reg.targetIsCrouching)
		{
			//std::cout << std::endl;
			//std::cout << "target is crouching" << std::endl;

			reg.target->GetStateMachine()->ClearQueuedStates();
			reg.target->GetStateMachine()->QueueNextState(new Fighter_0_States::F0_Crouch_Weak_Wince());
		}
		else
		{
			//std::cout << std::endl;
			//std::cout << "target is NOT crouching" << std::endl;

			if (attackSpecs.mAttackStrengthType._value == Collisions::AttackStrengthType::STRONG)
			{
				if (reg.collisionType == CollisionType::HEAD)
				{
					reg.target->GetStateMachine()->ClearQueuedStates();
					reg.target->GetStateMachine()->QueueNextState(new Fighter_0_States::F0_Strong_Wince_High());
				}
				else if (reg.collisionType == CollisionType::BODY)
				{
					reg.target->GetStateMachine()->ClearQueuedStates();
					reg.target->GetStateMachine()->QueueNextState(new Fighter_0_States::F0_Strong_Wince_Mid());
				}
			}
			else if (attackSpecs.mAttackStrengthType._value == Collisions::AttackStrengthType::WEAK)
			{
				reg.target->GetStateMachine()->ClearQueuedStates();
				reg.target->GetStateMachine()->QueueNextState(new Fighter_0_States::F0_Weak_Wince_Mid());
			}

			if (hitstopController != nullptr)
			{
				hitstopController->AddSkipFrames(attackSpecs.mHitStop);
			}
		}

		if (reg.target->GetHP() <= 0)
		{
			Updaters::ptrCurrentPlayground->SetFixedUpdateSkips(8);
			Updaters::ptrCurrentPlayground->ClearFixedUpdateSkip(12);
		}

		return true;
	}

	void AttackRegisterController::_ShowHitVFX(const AttackRegister& attackRegister)
	{
		auto vfxAnimationController = GET_VFX_ANIMATION_CONTROLLER;

		Render::iAnimationObj* hitVFX = vfxAnimationController->InstantiateAnimation(
			Sprites::SpriteType::vfx_hiteffect_0,
			attackRegister.collisionPoint,
			attackRegister.targetIsOnRightSide);
		
		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			4, 
			Render::OperationType::SINE, 
			1.4f));

		hitVFX->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			15,
			Render::OperationType::SINE, 
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
		auto vfxAnimationController = GET_VFX_ANIMATION_CONTROLLER;

		Render::iAnimationObj* hitVFX_word = nullptr;

		RandomGenerator randX;
		RandomGenerator randY;
		int x = randX.GetRand(10, 30);
		int y = randY.GetRand(10, 30);

		Vector2 pos;

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
			hitVFX_word = vfxAnimationController->InstantiateAnimation(
				Sprites::SpriteType::vfx_hiteffect_head,
				pos,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::BODY)
		{
			hitVFX_word = vfxAnimationController->InstantiateAnimation(
				Sprites::SpriteType::vfx_hiteffect_body,
				pos,
				true);
		}
		else if (attackRegister.collisionType == CollisionType::LEGS)
		{
			hitVFX_word = vfxAnimationController->InstantiateAnimation(
				Sprites::SpriteType::vfx_hiteffect_leg,
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
			Render::OperationType::SINE,
			float(rot)));

		hitVFX_word->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			5,
			Render::OperationType::SINE,
			1.4f));

		hitVFX_word->AddRenderScaleMultiplierObj(new Render::RenderScaleMultiplierObj(
			12,
			Render::OperationType::SINE,
			0.6f));
	}
}