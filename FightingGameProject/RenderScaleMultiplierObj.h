#pragma once

#include "RenderScaleMultiplierType.h"

#include "iAnimationObj.h"

namespace RB::Render
{
	class iAnimationObj; // forward declare

	class RenderScaleMultiplierObj
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier);

		void OnFixedUpdate();
		void SetOwner(iAnimationObj* owner);
		bool DoDelete();
		float GetRenderScaleMultiplier();

	private:
		int _totalFrames = 0;
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
		float _totalMultiplier = 1.0f;
		int _processedFrames = 0;
		iAnimationObj* _owner = nullptr;
	};
}
