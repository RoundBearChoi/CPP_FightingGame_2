#pragma once

namespace RB::Updaters
{
	template <class T>
	class SkipFixedUpdates
	{
	public:
		SkipFixedUpdates() = default;
		~SkipFixedUpdates() = default;

	public:
		void SetSkipFrames(unsigned int skipFrames)
		{
			_skipFrames = skipFrames;
		}

		void SetFunction(T* obj, void (T::*function)())
		{
			_obj = obj;
			_function = function;
		}

		void OnFixedUpdate()
		{
			if (_frameCount < _skipFrames)
			{
				_frameCount++;
			}
			else
			{
				_frameCount = 0;

				(_obj->*_function)();
			}
		}

	private:
		unsigned int _skipFrames = 0;
		unsigned int _frameCount = 0;
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}