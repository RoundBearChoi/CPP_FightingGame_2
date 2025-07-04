#include "AnimationRenderer.h"

#include "../Cam/GetRelPos.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer(AnimationSpecs specs)
	{
		_animationSpecs = specs;
	}

	void AnimationRenderer::OnFixedUpdate()
	{

	}

	const AnimationSpecs& AnimationRenderer::GetAnimationSpecs()
	{
		return _animationSpecs;
	}

	void AnimationRenderer::RenderAnimation(const RenderSettings& renderSettings)
	{
		auto camController = GET_CAM_CONTROLLER;

		if (_animationSpecs.mSpriteType._value == Sprites::SPRITE_TYPE::NONE)
		{
			return;
		}

		if (camController == nullptr)
		{
			return;
		}

		// get screen space x, y, width, height
		RB::Vector2 rel = RB::Cam::GetRelPos(camController->GetCamObj(), renderSettings.mWorldPos);  //camController->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float x = (float)rel.x;
		float y = (float)rel.y;

		float zoom = camController->GetCamObj()->GetZoom();

		x += renderSettings.mRenderOffset.x * zoom;
		y += renderSettings.mRenderOffset.y * zoom;

		float width = renderSettings.mSourceSize.x * renderSettings.mRenderScale * zoom;
		float height = renderSettings.mSourceSize.y * renderSettings.mRenderScale * zoom;

		// get quads
		std::array<RB::Vector2, 4> points = Sprites::GetQuadOnPivot(renderSettings.mPivotType, width, height, { x, y });

		// flip if necessary
		if (!renderSettings.mFaceRight)
		{
			points = Sprites::FlipQuad(renderSettings.mPivotType, points);
		}

		// rotate
		if (renderSettings.mRotation != 0.0f)
		{
			float r = 0.0f;

			if (!renderSettings.mFaceRight)
			{
				r = renderSettings.mRotation * -1.0f;
			}
			else
			{
				r = renderSettings.mRotation;
			}

			//std::cout << "rotating quad by " << renderSettings.mRotation << std::endl;
			points = Sprites::RotateQuad(points, r);
		}

		// convert to vf2d
		std::array<olc::vf2d, 4> arrVF2D;

		for (int i = 0; i < points.size(); i++)
		{
			arrVF2D[i] = { points[i].x, points[i].y };
		}

		olc::Pixel tint = olc::WHITE;
		tint.a = renderSettings.mTransparency;

		// render
		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(
			_animationSpecs.mLoadedSprite->GetDecal(),
			arrVF2D,
			olc::vf2d{ renderSettings.mSourcePos.x, renderSettings.mSourcePos.y },
			olc::vf2d{ renderSettings.mSourceSize.x, renderSettings.mSourceSize.y },
			tint);
	}
}
