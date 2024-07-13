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
		SizeChangeObj(int totalFrames, SizeChangeType sizeChangeType);

		void OnFixedUpdate();
		bool DoDelete();

	private:
		int _totalFrames = 0;
		SizeChangeType _sizeChangeType = SizeChangeType::NONE;
		int _processedFrames = 0;
	};
}
