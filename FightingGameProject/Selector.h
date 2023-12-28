#pragma once
#include <vector>

namespace RB
{
	template<class T>
	class Selector
	{
	public:
		Selector()
		{

		}

		~Selector()
		{

		}

	public:
		void OnFixedUpdate()
		{
			_Refresh();
		}

		const std::vector<T>& GetVector()
		{
			return _vec;
		}

		void PushBack(T t)
		{
			_vec.push_back(t);

			_refreshed = false;
		}

		void EraseSelected()
		{
			_iterator = _vec.erase(_iterator);

			_refreshed = false;
		}

		void EraseByIndex(unsigned int index)
		{
			auto i = _vec.begin() + index;

			_iterator = _vec.erase(i);

			_refreshed = false;
		}

		T* GetSelected()
		{
			if (_vec.empty())
			{
				return nullptr;
			}

			if (!_refreshed || !_initialized)
			{
				return nullptr;
			}

			return &(*_iterator);
		}

		T* GetByIndex(unsigned int index)
		{
			if (_vec.empty())
			{
				return nullptr;
			}

			if (!_initialized || !_refreshed)
			{
				return nullptr;
			}

			auto i = _vec.begin() + index;

			if (i < _vec.begin() || i >= _vec.end())
			{
				return nullptr;
			}
			
			return &(*i);
		}
		
		void SelectUp()
		{
			if (!_refreshed)
			{
				return;
			}

			_iterator++;

			_CycleSelector();
		}

		void SelectDown()
		{
			if (!_refreshed)
			{
				return;
			}

			_iterator--;

			_CycleSelector();
		}

	private:
		void _CycleSelector()
		{
			if (_iterator < _vec.begin())
			{
				_iterator = _vec.end() - 1;
			}
			else if (_iterator >= _vec.end())
			{
				_iterator = _vec.begin();
			}
		}

		void _Refresh()
		{
			if (!_refreshed)
			{
				_initialized = true;
				_refreshed = true;
				_iterator = _vec.end() - 1;
			}
		}

	private:
		bool _fixedUpdated = false;
		bool _initialized = false;
		bool _refreshed = true;
		std::vector<T>::iterator _iterator;
		std::vector<T> _vec;
	};
}