#pragma once

#include <iostream>
#include <string>

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
		
		public:
		void SetOwner(iAnimationObj* owner);
		bool DoDelete();
		float GetRenderScaleMultiplier();
		void SetStartAndEnd();
		
		private:
		int _totalFrames = 0;
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
		float _totalMultiplier = 1.0f;
		int _processedFrames = 0;
		iAnimationObj* _owner = nullptr;
		float _start = 0.0f;
		float _end = 0.0f;
	};
}
