#pragma once

namespace RB::HurtBox
{
	class HurtBoxData
	{
	public:
		HurtBoxData() = default;
		~HurtBoxData() = default;

		int mX = 0;
		int mY = 0;
		float mWidth = 0; //even numbers?
		float mWeight = 0; //even numbers?
	};
}