#pragma once

#include "../Vector2.h"
#include "../Sprites/PivotType.h"

namespace RB::Render
{
	class RenderSettings
	{
	public:
		RenderSettings() = default;
		~RenderSettings() = default;

	public:
		unsigned int mCurrentIndex = 0;
		RB::Vector2 mSourcePos = { 0.0f, 0.0f };
		RB::Vector2 mSourceSize = { 0.0f, 0.0f };
		RB::Vector2 mWorldPos = { 0.0f, 0.0f };
		float mRenderScale = 1.0f;
		float mRotation = 0.0f;
		int mTransparency = 255;
		RB::Vector2 mRenderOffset = { 0.0f, 0.0f };
		Sprites::PivotType mPivotType = Sprites::PivotType::NONE;
		bool mFaceRight = true;
	};
}
