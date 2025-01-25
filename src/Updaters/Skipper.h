#pragma once

#include "iSkipper.h"

namespace RB::Updaters
{
	class Skipper : public iSkipper
	{
	public:
		Skipper() = default;
		~Skipper() = default;

	public:
		void SetSkipFrames(unsigned int skipFrames) override;
		void ClearSkipFrames() override;
		void SetFunction(std::function<void()> func) override;
		bool DoFixedUpdate() override;
		unsigned int GetTotalFixedUpdateCount() override;

	protected:
		unsigned int _skipFrames = 0;
		unsigned int _frameCount = 0;
		unsigned int _totalFrameCount = 0;
		std::function<void()> _func = nullptr;
	};
}