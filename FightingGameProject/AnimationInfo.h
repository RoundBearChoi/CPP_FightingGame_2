#pragma once
#include "olcPixelGameEngine.h"
#include "PivotType.h"

namespace RB::Render
{
	class AnimationInfo
	{
	public:
		AnimationInfo() {}
		~AnimationInfo() {}

	public:
		unsigned int mCurrentIndex = 0;
		olc::vf2d mSourcePos = { 0.0f, 0.0f };
		olc::vf2d mSourceSize = { 0.0f, 0.0f };
		olc::vi2d mWorldPos = { 0, 0 };
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		RB::Sprites::PivotType mPivotType = RB::Sprites::PivotType::NONE;
	};
}