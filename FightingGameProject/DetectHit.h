#pragma once
#include "StateComponentBase.h"

#include "iPlayer.h"
#include "olcPixelGameEngine.h"
#include "SpriteType.h"
#include "AttackCollisionYType.h"
#include "CollisionResult.h"

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
		RB::Collisions::AttackCollisionYType _GetAttackCollisionYType(RB::Players::iPlayer* target, olc::vf2d& collisionPoint);

		int _hits = 0;
		int _fixedUpdatesSinceLastHit = 0;
	};
}