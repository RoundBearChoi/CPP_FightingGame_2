#pragma once

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

	private:
		float _x = 0.0f;
		float _y = 0.0f;
		float _width = 0.0f;
		float _height = 0.0f;
	};

	//bool checkAABBCollision(AABB a, AABB b) {
	//	return (a.x < b.x + b.width && a.x + a.width > b.x && a.y < b.y + b.height && a.y + a.height > b.y);
	//}
}