#pragma once

#include "AttackSpecs.h"

#include "../Controllers/ControllerBase.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	#define GET_ATTACK_SPECS_CONTROLLER static_cast<Collisions::iAttackSpecsController*>(Controllers::GetController(Controllers::ControllerType::ATTACK_SPECS_CONTROLLER))

	class iAttackSpecsController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		const virtual Collisions::AttackSpecs& GetAttackSpecs(Sprites::SPRITE_TYPE spriteType) = 0;
		virtual bool ContainsAttackSpecs(Sprites::SPRITE_TYPE spriteType) = 0;
	};
}
