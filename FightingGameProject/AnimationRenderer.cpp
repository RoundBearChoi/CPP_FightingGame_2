#include "AnimationRenderer.h"

#include "iCamController.h"

#include "GetQuadOnPivot.h"
#include "FlipQuad.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer(AnimationSpecs specs)
	{
		_animationSpecs = specs;
	}

	void AnimationRenderer::OnFixedUpdate()
	{
		//if (_vecSizeChangeObjs.size() >= 1)
		//{
		//	_vecSizeChangeObjs[0].OnFixedUpdate();
		//
		//	if (_vecSizeChangeObjs[0].DoDelete())
		//	{
		//		_vecSizeChangeObjs.erase(_vecSizeChangeObjs.begin());
		//	}
		//}
	}

	const AnimationSpecs& AnimationRenderer::GetAnimationSpecs()
	{
		return _animationSpecs;
	}

	void AnimationRenderer::RenderAnimation(const RenderSettings& renderSettings)
	{
		if (_animationSpecs.mSpriteType._value == RB::Sprites::SpriteType::NONE)
		{
			return;
		}

		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		// get screen space x, y, width, height
		olc::vf2d rel = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(renderSettings.mWorldPos);

		float x = (float)rel.x;
		float y = (float)rel.y;

		float zoom = RB::Cam::iCamController::Get()->GetCamObj()->GetZoom();

		x += renderSettings.mRenderOffset.x * zoom;
		y += renderSettings.mRenderOffset.y * zoom;

		float width = renderSettings.mSourceSize.x * renderSettings.mRenderScale * zoom;
		float height = renderSettings.mSourceSize.y * renderSettings.mRenderScale * zoom;

		// get quads
		std::array<olc::vf2d, 4> points = RB::Sprites::GetQuadOnPivot(renderSettings.mPivotType, width, height, { x, y });

		// flip if necessary
		if (!renderSettings.mFaceRight)
		{
			points = RB::Sprites::FlipQuad(renderSettings.mPivotType, points);
		}

		// render
		olc::Renderer::ptrPGE->DrawPartialWarpedDecal(_animationSpecs.mLoadedSprite->GetDecal(), points, renderSettings.mSourcePos, renderSettings.mSourceSize);

		olc::Renderer::ptrPGE->SetDrawTarget(nullptr);
	}

	//void AnimationRenderer::AddSizeChangeObj(SizeChangeObj obj)
	//{
	//	_vecSizeChangeObjs.push_back(obj);
	//}
}
