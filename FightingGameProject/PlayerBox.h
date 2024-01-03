#pragma once

namespace RB::Collisions
{
	class PlayerBox
	{
	public:
		PlayerBox() = default;

		PlayerBox(unsigned int frame, float offsetX, float offsetY, float width, float height)
		{
			mFrame = frame;
			mOffsetX = offsetX;
			mOffsetY = offsetY;
			mWidth = width;
			mHeight = height;
		}

		~PlayerBox() = default;

	public:
		unsigned int mFrame = 0;
		float mOffsetX = 0.0f;
		float mOffsetY = 0.0f;
		float mWidth = 0.0f;
		float mHeight = 0.0f;
	};
}