#pragma once

namespace RB::HurtBox
{
	class HurtBoxSpecs
	{
	public:
		HurtBoxSpecs() = default;
		~HurtBoxSpecs() = default;

		int32_t mX = 0;
		int32_t mY = 0;
		float mWidth = 0; //even numbers?
		float mWeight = 0; //even numbers?
	};
}