#pragma once

#include <vector>

#include "AttackSpecs.h"

#include "iAttackSpecsController.h"
#include "iAttackRegisterController.h"
#include "iGeneralHitStopController.h"

#include "../SpriteType.h"
#include "../Render/RenderScaleMultiplierObj.h"

#include "../P0_Wince.h" //temp
#include "../P0_Strong_Wince.h" //temp

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
	};
}
