#pragma once

namespace RB::HurtBox
{
	class HurtBoxSpecs
	{
	public:
		HurtBoxSpecs() = default;

		HurtBoxSpecs(int32_t x, int32_t y, float width, float weight)
		{
			_x = x;
			_y = y;
			_width = width;
			_height = weight;
		}

		~HurtBoxSpecs() = default;

	public:
		const int32_t& GetX()
		{
			return _x;
		}

		const int32_t& GetY()
		{
			return _y;
		}

		const float& GetWidth()
		{
			return _width;
		}

		const float& GetHeight()
		{
			return _height;
		}

	private:
		int32_t _x = 0;
		int32_t _y = 0;
		float _width = 0; //even numbers using int?
		float _height = 0; //even numbers using int?
	};
}