#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Collisions
{
	class AABB
	{
	public:
		AABB(float bottomLeftX, float bottomLeftY, float width, float height)
		{
			_bottomLeftX = bottomLeftX;
			_bottomLeftY = bottomLeftY;
			_width = width;
			_height = height;
		}

		~AABB()
		{

		}

	public:
		void SetBottomLeft(float bottomLeftX, float bottomLeftY)
		{
			_bottomLeftX = bottomLeftX;
			_bottomLeftY = bottomLeftY;
		}

		olc::vf2d GetBottomLeft()
		{
			return olc::vf2d{ _bottomLeftX, _bottomLeftY };
		}

		bool IsCollidingAgainst(AABB& other)
		{
			return (_bottomLeftX < other._bottomLeftX + other._width && _bottomLeftX + _width > other._bottomLeftX && _bottomLeftY < other._bottomLeftY + other._height && _bottomLeftY + _height > other._bottomLeftY);
		}

	private:
		float _bottomLeftX = 0.0f;
		float _bottomLeftY = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};
}