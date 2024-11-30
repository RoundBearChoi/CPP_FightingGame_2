#pragma once

#include <string>

#include "../Sprites/SpriteType.h"
#include "../Collisions/AttackSpecs.h"
#include "../Players/PlayerState.h"
#include "../Collisions/CollisionResult.h"
#include "../States/StateComponentBase.h"

#include "../Players/iPlayer.h"
#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"
#include "../HBox/iTargetBoxDataController.h"
#include "../HBox/iAttackBoxDataController.h"
#include "../Collisions/iAttackRegisterController.h"
#include "../Collisions/iAttackSpecsController.h"

#include "../Fighter_0_States/F0_Weak_Wince_Mid.h" //temp

namespace RB::PlayerStateComponents
{
	class DetectHit : public RB::States::StateComponentBase
	{
	public:
		DetectHit() = default;
		~DetectHit() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		void _ProcessHit();
		bool _HitDetected(RB::Collisions::CollisionResult& collisionResult);
		void _RegisterHit(RB::Collisions::CollisionResult& collisionResult);
		void _AddFixedUpdatesSinceLastHit();

		int _hits = 0;
		int _fixedUpdatesSinceLastHit = 0;
	};
}
