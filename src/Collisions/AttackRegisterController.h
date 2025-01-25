#pragma once

#include <vector>

#include "AttackSpecs.h"
#include "AttackRegister.h"
#include "CollisionType.h"

#include "iAttackSpecsController.h"
#include "iAttackRegisterController.h"
#include "iHitStopController.h"

#include "../RandomGenerator.h"
#include "../Sprites/SpriteType.h"
#include "../Render/RenderScaleMultiplierObj.h"
#include "../Render/RenderRotationObj.h"

#include "../Fighter_0_States/F0_Weak_Wince_Mid.h" //temp
#include "../Fighter_0_States/F0_Strong_Wince_Mid.h" //temp
#include "../Fighter_0_States/F0_Strong_Wince_High.h" //temp
#include "../Fighter_0_States/F0_Crouch_Weak_Wince.h"

#include "../Render/iAnimationObj.h"
#include "../Render/iVFXAnimationController.h"

namespace RB::Collisions
{
	class AttackRegisterController : public iAttackRegisterController
	{
	public:
		AttackRegisterController() = default;
		~AttackRegisterController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		bool RegisterAttack(AttackRegister reg) override;

	private:
		void _ShowHitVFX(const AttackRegister& attackRegister);
		void _ShowHitLocation(const AttackRegister& attackRegister);
	};
}