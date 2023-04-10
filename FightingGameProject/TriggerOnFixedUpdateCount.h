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
			static_assert(std::is_base_of<RB::States::iState, T>::value, "T must be derived from iState");
			
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
				if (!_functionCalled)
				{
					unsigned int currentFixedUpdates = _state->GetCumulatedFixedUpdates();

					if (currentFixedUpdates >= _targetFixedUpdate)
					{
						(_obj->*_function)();

						_functionCalled = true;
					}
				}
			}
		}

	private:
		unsigned int _targetFixedUpdate = 0;
		T* _obj = nullptr;
		RB::States::iState* _state = nullptr;
		bool _stateFound = false;
		bool _functionCalled = false;
		void (T::* _function)() = nullptr;
	};
}