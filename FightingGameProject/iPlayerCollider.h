#pragma once

#include "olcPixelGameEngine.h"
#include "AABB.h"

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
		virtual void SetPlayerBox(olc::vf2d widthHeight) = 0;
		virtual bool IsCollidingAgainstOtherPlayer() = 0;
		virtual RB::Collisions::AABB& GetAABB() = 0;
	};
}