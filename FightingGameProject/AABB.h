#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Collisions
{
	class AABB
	{
	public:
		AABB(float x, float y, float width, float height)
		{
			_x = x;
			_y = y;
			_width = width;
			_height = height;
		}

		~AABB()
		{

		}

	public:
		olc::vf2d GetBottomLeft()
		{
			return olc::vf2d{ _x, _y };
		}

		bool IsCollidingAgainst(AABB& other)
		{
			return (_x < other._x + other._width && _x + _width > other._x && _y < other._y + other._height && _y + _height > other._y);
		}

	private:
		float _x = 0.0f;
		float _y = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};
}