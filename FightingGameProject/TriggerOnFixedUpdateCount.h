#pragma once
#include "iState.h"

namespace RB::Updaters
{
	template <class T>
	class TriggerOnFixedUpdateCount
	{
	public:
		void SetTargetFixedUpdate(unsigned int target)
		{
			_targetFixedUpdate = target;
		}

		void SetFunction(T* obj, void (T::* function)())
		{
			_state = dynamic_cast<RB::States::iState*>(obj);

			if (_state != nullptr)
			{
				_obj = obj;
				_function = function;

				_stateFound = true;
			}
		}

		void OnFixedUpdate()
		{
			if (_stateFound)
			{
				if (_targetFixedUpdate >= _state->GetCumulatedFixedUpdates())
				{
					(_obj->*_function)();
				}
			}
		}

	private:
		unsigned int _targetFixedUpdate = 0;
		T* _obj = nullptr;
		RB::States::iState _state = nullptr;
		bool _stateFound = false;
		void (T::* _function)() = nullptr;
	};
}