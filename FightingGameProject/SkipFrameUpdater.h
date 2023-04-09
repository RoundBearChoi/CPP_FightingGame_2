#pragma once

namespace RB::Updaters
{
	//class RB::Players::PlayerTestState;
	template <typename T, void (T::*Func)()>
	class SkipFrameUpdater
	{
	public:
		SkipFrameUpdater(int skipFrames, void (*some)());
		~SkipFrameUpdater();

		void OnUpdate();

	private:
		int _skipFrames = 0;
		void (*sdfdsfdsfdsfsdfvv)();
	};


}