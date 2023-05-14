#pragma once
#include "olcPixelGameEngine.h"
#include "PivotType.h"

namespace RB::Render
{
	class AnimationRenderSettings
	{
	public:
		AnimationRenderSettings() = default;
		~AnimationRenderSettings() = default;

	public:
		uint32_t mCurrentIndex = 0;
		olc::vf2d mSourcePos = { 0.0f, 0.0f };
		olc::vf2d mSourceSize = { 0.0f, 0.0f };
		olc::vi2d mWorldPos = { 0, 0 };
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		olc::vf2d mRenderOffset = { 0.0f, 0.0f };
		RB::Sprites::PivotType mPivotType = RB::Sprites::PivotType::NONE;
		bool mFaceRight = true;
	};
}