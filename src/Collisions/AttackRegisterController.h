#pragma once

#include <vector>

#include "AttackSpecs.h"
#include "AttackRegister.h"
#include "CollisionType.h"

#include "iAttackSpecsController.h"
#include "iAttackRegisterController.h"
#include "iGeneralHitStopController.h"

#include "../RandomGenerator.h"
#include "../Sprites/SpriteType.h"
#include "../Render/RenderScaleMultiplierObj.h"
#include "../Render/RenderRotationObj.h"

#include "../Fighter_0_States/F0_Weak_Wince_Mid.h" //temp
#include "../Fighter_0_States/F0_Strong_Wince_Mid.h" //temp

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

		void RegisterAttack(AttackRegister reg) override;

	private:
		void ShowHitVFX(const AttackRegister& attackRegister);
		void ShowHitLocation(const AttackRegister& attackRegister);
	};
}
