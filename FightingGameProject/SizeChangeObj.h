#pragma once

namespace RB::Render
{
	enum class SizeChangeType
	{
		NONE,

		LINEAR,
		
		COUNT,
	};

	class SizeChangeObj
	{
	public:
		SizeChangeObj(int totalFrames, SizeChangeType sizeChangeType, float totalSizeChangeMultiplier);

		void OnFixedUpdate();
		bool DoDelete();
		float GetRenderSizeMultiplier();

	private:
		int _totalFrames = 0;
		SizeChangeType _sizeChangeType = SizeChangeType::NONE;
		float _totalSizeChangeMultiplier = 1.0f;
		int _processedFrames = 0;
	};
}
