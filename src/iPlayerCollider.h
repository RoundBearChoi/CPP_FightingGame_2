#pragma once

#include "Collisions/AABB.h"
#include "Collisions/PlayerBox.h"

namespace RB::Players
{
	class iPlayerCollider
	{
	public:
		iPlayerCollider() = default;
		virtual ~iPlayerCollider() {};

	public:
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual RB::Vector2 GetPlayerBox() = 0;
		virtual void SetPlayerBox(const RB::Collisions::PlayerBox& box) = 0;
		virtual bool IsCollidingAgainstOtherPlayer() = 0;
		virtual const RB::Collisions::AABB& GetAABB() = 0;
		virtual RB::Collisions::AABB* GetAABB_ptr() = 0;
		virtual float* GetBodyParts() = 0;
	};
}
