#pragma once

namespace RB::Collisions
{
	class PlayerBox
	{
	public:
		PlayerBox() = default;
		~PlayerBox() = default;

	public:
		unsigned int mFrame = 0;
		float mOffsetX = 0.0f;
		float mOffsetY = 0.0f;
		float mWidth = 0.0f;
		float mHeight = 0.0f;
	};
}