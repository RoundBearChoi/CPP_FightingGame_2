#include "AABB.h"

namespace RB::Collisions
{
	AABB::AABB(float bottomLeftX, float bottomLeftY, float width, float height)
	{
		_bottomLeftX = bottomLeftX;
		_bottomLeftY = bottomLeftY;
		_width = width;
		_height = height;
	}

	void AABB::SetBottomLeft(float bottomLeftX, float bottomLeftY)
	{
		_bottomLeftX = bottomLeftX;
		_bottomLeftY = bottomLeftY;
	}

	void AABB::SetWidthHeight(float width, float height)
	{
		_width = width;
		_height = height;
	}

	void AABB::MoveX(float x)
	{
		_bottomLeftX += x;
	}

	void AABB::MoveY(float y)
	{
		_bottomLeftY += y;
	}

	void AABB::IncreaseWidth(float amount)
	{
		_width += amount;

		if (_width < 0.0f)
		{
			_width = 0.0f;
		}
	}

	void AABB::IncreaseHeight(float amount)
	{
		_height += amount;

		if (_height < 0.0f)
		{
			_height = 0.0f;
		}
	}

	Vector2 AABB::GetCenter()
	{
		return Vector2{ _bottomLeftX + (_width * 0.5f), _bottomLeftY - (_height * 0.5f) };
	}

	Vector2 AABB::GetBottomLeft()
	{
		return Vector2{ _bottomLeftX, _bottomLeftY };
	}

	Vector2 AABB::GetWidthHeight()
	{
		return Vector2{ _width, _height };
	}

	// up is -y for olc
	bool AABB::IsCollidingAgainst(const AABB& other, Vector2& collisionCenter)
	{
		if (_width <= 0.001f || _height <= 0.001f)
		{
			return false;
		}

		if (other._width <= 0.001f || other._height <= 0.001f)
		{
			return false;
		}

		bool horizontalCol_L = _bottomLeftX < other._bottomLeftX + other._width;
		bool horizontalCol_R = _bottomLeftX + _width > other._bottomLeftX;
		bool verticalCol_B = _bottomLeftY > other._bottomLeftY - other._height;
		bool verticalCol_U = _bottomLeftY - _height < other._bottomLeftY;

		if (horizontalCol_L && horizontalCol_R && verticalCol_B && verticalCol_U)
		{
			collisionCenter = GetCollisionCenter(other);

			return true;
		}

		return false;
	}

	// olc y is reversed
	Vector2 AABB::GetCollisionCenter(const AABB& other)
	{
		float minxX = std::max(_bottomLeftX, other._bottomLeftX);
		float minY = std::min(_bottomLeftY, other._bottomLeftY);

		float maxX = std::min(_bottomLeftX + _width, other._bottomLeftX + other._width);
		float maxY = std::max(_bottomLeftY - _height, other._bottomLeftY - other._height);

		return { (minxX + maxX) * 0.5f, (minY + maxY) * 0.5f };
	}

	AABB AABB::GetWorldPos(const Vector2& playerPos, const bool& otherPlayerIsOnRightSide)
	{
		AABB worldAABB{ 0.0f, 0.0f, _width, _height };

		if (otherPlayerIsOnRightSide)
		{
			worldAABB.SetBottomLeft(playerPos.x + _bottomLeftX, playerPos.y + _bottomLeftY);
		}
		else
		{
			worldAABB.SetBottomLeft(playerPos.x - _bottomLeftX - _width, playerPos.y + _bottomLeftY);
		}

		return worldAABB;
	}

	void AABB::ForceAABB(AABB& aabb)
	{
		_bottomLeftX = aabb._bottomLeftX;
		_bottomLeftY = aabb._bottomLeftY;
		_width = aabb._width;
		_height = aabb._height;
	}
}