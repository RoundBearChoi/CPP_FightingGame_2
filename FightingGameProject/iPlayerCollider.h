#pragma once

#include "olcPixelGameEngine.h"
#include "AABB.h"
#include "PlayerBox.h"

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

		virtual olc::vf2d GetPlayerBox() = 0;
		virtual void SetPlayerBox(const RB::Collisions::PlayerBox& box) = 0;
		virtual bool IsCollidingAgainstOtherPlayer() = 0;
		virtual const RB::Collisions::AABB& GetAABB() = 0;
		virtual RB::Collisions::AABB* GetAABB_ptr() = 0;
	};
}