#pragma once

#include <algorithm>

#include "Vector2.h"

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
		RB::Vector2 GetCenter();
		RB::Vector2 GetBottomLeft();
		RB::Vector2 GetWidthHeight();
		bool IsCollidingAgainst(const AABB& other, RB::Vector2& collisionCenter);
		RB::Vector2 GetCollisionCenter(const AABB& other);
		AABB GetWorldPos(const RB::Vector2& playerPos, const bool& otherPlayerIsOnRightSide);
		void ForceAABB(AABB& aabb);

	private:
		float _bottomLeftX = 0.0f;
		float _bottomLeftY = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};
}
