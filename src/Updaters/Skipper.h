#pragma once

#include <functional>

namespace RB::Updaters
{
	class Skipper
	{
	public:
		Skipper() = default;
		~Skipper() = default;

	public:
		void SetSkipFrames(unsigned int skipFrames);
		void ClearSkipFrames();
		void SetFunction(std::function<void()> func);
		bool DoFixedUpdate();
		unsigned int GetTotalFixedUpdateCount();

	private:
		unsigned int _skipFrames = 0;
		unsigned int _frameCount = 0;
		unsigned int _totalFrameCount = 0;
		std::function<void()> _func = nullptr;
	};
}