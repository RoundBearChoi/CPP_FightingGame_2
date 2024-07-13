#pragma once
#include "olcPixelGameEngine.h"
#include "PivotType.h"

namespace RB::Render
{
	class RenderSettings
	{
	public:
		RenderSettings() = default;
		~RenderSettings() = default;

	public:
		unsigned int mCurrentIndex = 0;
		olc::vf2d mSourcePos = { 0.0f, 0.0f };
		olc::vf2d mSourceSize = { 0.0f, 0.0f };
		olc::vf2d mWorldPos = { 0.0f, 0.0f };
		float mRenderScale = 1.0f;
		float mRenderSizeMultiplier = 1.0f;
		olc::vf2d mRenderOffset = { 0.0f, 0.0f };
		RB::Sprites::PivotType mPivotType = RB::Sprites::PivotType::NONE;
		bool mFaceRight = true;
	};
}
