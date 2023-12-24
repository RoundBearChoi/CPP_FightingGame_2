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

		virtual olc::vi2d GetPlayerBox() = 0;
		virtual bool IsColliding() = 0;
		virtual RB::Collisions::AABB& UpdateAABBOnPlayerPos() = 0;
	};
}