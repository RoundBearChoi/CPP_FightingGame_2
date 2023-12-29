#pragma once
#include <vector>

#include "iSelector.h"

namespace RB
{
	template<class T>
	class Selector : public iSelector<T>
	{
	public:
		Selector()
		{

		}

		~Selector() override
		{

		}

	public:
		void OnFixedUpdate() override
		{
			_Refresh();
		}

		const std::vector<T>& GetVector() override
		{
			return _vec;
		}

		void PushBack(T t) override
		{
			_vec.push_back(t);

			_refreshed = false;
		}

		void EraseSelected() override
		{
			if (_vec.empty())
			{
				return;
			}

			_iterator = _vec.erase(_iterator);

			_refreshed = false;
		}

		void EraseByIndex(unsigned int index) override
		{
			if (_vec.empty())
			{
				return;
			}

			auto i = _vec.begin() + index;

			_iterator = _vec.erase(i);

			_refreshed = false;
		}

		T* GetSelected() override
		{
			if (_vec.empty())
			{
				return nullptr;
			}

			if (!_refreshed)
			{
				return nullptr;
			}

			return &(*_iterator);
		}

		T* GetByIndex(unsigned int index) override
		{
			if (_vec.empty())
			{
				return nullptr;
			}

			if (!_refreshed)
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
		
		void SelectUp() override
		{
			if (_vec.empty())
			{
				return;
			}

			if (!_refreshed)
			{
				return;
			}

			if (_iterator == _vec.end() - 1)
			{
				_iterator = _vec.begin();
			}
			else
			{
				_iterator++;
			}
		}

		void SelectDown() override
		{
			if (_vec.empty())
			{
				return;
			}

			if (!_refreshed)
			{
				return;
			}

			if (_iterator == _vec.begin())
			{
				_iterator = _vec.end() - 1;
			}
			else
			{
				_iterator--;
			}
		}

		bool IsEmpty() override
		{
			return _vec.empty();
		}

		void SetRefreshed(bool refreshed) override
		{
			_refreshed = refreshed;
		}

	private:
		void _Refresh()
		{
			if (_vec.empty())
			{
				_refreshed = false;
				return;
			}

			if (!_refreshed)
			{
				_refreshed = true;
				_iterator = _vec.end() - 1;
			}
		}

	private:
		bool _fixedUpdated = false;
		bool _refreshed = true;
		std::vector<T>::iterator _iterator;
		std::vector<T> _vec;
	};
}