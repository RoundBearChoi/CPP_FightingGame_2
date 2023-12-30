#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Collisions
{
	class AABB
	{
	public:
		AABB() = default;
		AABB(float bottomLeftX, float bottomLeftY, float width, float height);
		~AABB() = default;

	public:
		void SetBottomLeft(float bottomLeftX, float bottomLeftY);
		void SetWidthHeight(float width, float height);
		void MoveX(float x);
		void MoveY(float y);
		void IncreaseWidth(float amount);
		void IncreaseHeight(float amount);
		olc::vf2d GetCenter();
		olc::vf2d GetBottomLeft();
		olc::vf2d GetWidthHeight();
		bool IsCollidingAgainst(const AABB& other, olc::vf2d& collisionCenter);
		olc::vf2d GetCollisionCenter(const AABB& other);
		AABB GetWorldPos(const olc::vf2d& playerPos, const bool& otherPlayerIsOnRightSide);
		void ForceAABB(AABB& aabb);

	private:
		float _bottomLeftX = 0.0f;
		float _bottomLeftY = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};
}