#pragma once
#include "olcPixelGameEngine.h"

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

		bool IsCollidingAgainst(const AABB& other)
		{
			return (_bottomLeftX < other._bottomLeftX + other._width && _bottomLeftX + _width > other._bottomLeftX && _bottomLeftY < other._bottomLeftY + other._height && _bottomLeftY + _height > other._bottomLeftY);
		}

	private:
		float_t _bottomLeftX = 0.0f;
		float_t _bottomLeftY = 0.0f;
		float_t _width = 0.0f;
		float_t _height = 0.0f;
	};
}