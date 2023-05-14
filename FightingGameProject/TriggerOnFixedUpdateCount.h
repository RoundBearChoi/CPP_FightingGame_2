#pragma once
#include "iState.h"

namespace RB::Updaters
{
	template <class T>
	class TriggerOnFixedUpdateCount
	{
	public:
		TriggerOnFixedUpdateCount() = default;
		~TriggerOnFixedUpdateCount() = default;

	public:
		void SetTargetFixedUpdate(unsigned int target)
		{
			_targetFixedUpdate = target;
		}

		void SetFunction(T* obj, void (T::* function)())
		{
			_obj = obj;
			_function = function;
		}

		void OnFixedUpdate()
		{
			if (!_functionCalled)
			{
				if (_cumulatedFixedUpdates >= _targetFixedUpdate)
				{
					(_obj->*_function)();

					_functionCalled = true;
				}
			}

			_cumulatedFixedUpdates++;
		}

	private:
		size_t _cumulatedFixedUpdates = 0;
		size_t _targetFixedUpdate = 0;
		bool _functionCalled = false;

	private:
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}