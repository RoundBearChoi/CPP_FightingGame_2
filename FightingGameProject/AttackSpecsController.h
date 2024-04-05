#pragma once

#include "iAttackSpecsController.h"

#include "SpriteType.h"

namespace RB::Collisions
{
	class AttackSpecsController : public iAttackSpecsController
	{
	public:
		AttackSpecsController() = default;
		~AttackSpecsController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		RB::Collisions::AttackSpecs GetAttackSpecs(RB::Sprites::SpriteType spriteType) override;

	private:
		void _LoadAttackSpecs();
		void _Load(std::string path, RB::Sprites::SpriteType spriteType);
	};
}