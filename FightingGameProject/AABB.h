#pragma once
#include "olcPixelGameEngine.h"
#include <algorithm>

namespace RB::Collisions
{
	class AABB
	{
	public:
		AABB() = default;

		AABB(float_t bottomLeftX, float_t bottomLeftY, float_t width, float_t height)
		{
			_bottomLeftX = bottomLeftX;
			_bottomLeftY = bottomLeftY;
			_width = width;
			_height = height;
		}

		~AABB() = default;

	public:
		void SetBottomLeft(float_t bottomLeftX, float_t bottomLeftY)
		{
			_bottomLeftX = bottomLeftX;
			_bottomLeftY = bottomLeftY;
		}

		void MoveX(float_t x)
		{
			_bottomLeftX += x;
		}

		void MoveY(float_t y)
		{
			_bottomLeftY += y;
		}

		void IncreaseWidth(float_t amount)
		{
			_width += amount;

			if (_width < 0.0f)
			{
				_width = 0.0f;
			}
		}

		void IncreaseHeight(float_t amount)
		{
			_height += amount;

			if (_height < 0.0f)
			{
				_height = 0.0f;
			}
		}

		olc::vf2d GetCenter()
		{
            return olc::vf2d{ _bottomLeftX + (_width * 0.5f), _bottomLeftY - (_height * 0.5f) };
		}

		olc::vf2d GetBottomLeft()
		{
			return olc::vf2d{ _bottomLeftX, _bottomLeftY };
		}

		olc::vf2d GetWidthHeight()
		{
			return olc::vf2d{ _width, _height };
		}

		/// <summary>
		/// up is -y for olc
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		bool IsCollidingAgainst(const AABB& other, olc::vf2d& collisionCenter)
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

		olc::vf2d GetCollisionCenter(const AABB& other)
		{
			float_t minxX = std::max(_bottomLeftX, other._bottomLeftX); //min vs min
			float_t minY = std::min(_bottomLeftY, other._bottomLeftY);

			float_t maxX = std::min(_bottomLeftX + _width, other._bottomLeftX + other._width);
			float_t maxY = std::max(_bottomLeftY - _height, other._bottomLeftY - other._height);

			return { (minxX + maxX) * 0.5f, (minY + maxY) * 0.5f };
		}

		AABB GetWorldPos(const olc::vf2d& playerPos, const bool& otherPlayerIsOnRightSide)
		{

			AABB worldAABB{ 0.0f, 0.0f, _width, _height };

			if (otherPlayerIsOnRightSide)
			{
				worldAABB.SetBottomLeft(playerPos.x + _bottomLeftX, playerPos.y + _bottomLeftY);
			}
			else
			{
				worldAABB.SetBottomLeft(playerPos.x - _bottomLeftX -_width, playerPos.y + _bottomLeftY);
			}

			return worldAABB;
		}

	private:
		float_t _bottomLeftX = 0.0f;
		float_t _bottomLeftY = 0.0f;
		float_t _width = 0.0f;
		float_t _height = 0.0f;
	};
}