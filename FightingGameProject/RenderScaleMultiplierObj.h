#pragma once

namespace RB::Render
{
	enum class RenderScaleMultiplierType
	{
		NONE,

		LINEAR,
		
		COUNT,
	};

	class RenderScaleMultiplierObj
	{
	public:
		RenderScaleMultiplierObj(int totalFrames, RenderScaleMultiplierType multiplierType, float totalMultiplier);

		void OnFixedUpdate();
		bool DoDelete();
		float GetRenderScaleMultiplier();

	private:
		int _totalFrames = 0;
		RenderScaleMultiplierType _multiplierType = RenderScaleMultiplierType::NONE;
		float _totalMultiplier = 1.0f;
		int _processedFrames = 0;
	};
}
