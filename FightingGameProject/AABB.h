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

		~AABB() = default;

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

	public:
		static bool IsColliding(const AABB& a, const AABB& b)
		{
			return (a._bottomLeftX < b._bottomLeftX + b._width && a._bottomLeftX + a._width > b._bottomLeftX && a._bottomLeftY < b._bottomLeftY + b._height && a._bottomLeftY + a._height > b._bottomLeftY);
		}

	private:
		float _bottomLeftX = 0.0f;
		float _bottomLeftY = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};
}