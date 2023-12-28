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
		void Init()
		{

		}

		void OnFixedUpdate()
		{

		}

		void PushBack(T t)
		{
			_vec.push_back(t);
		}

	private:
		bool _fixedUpdated = false;
		bool _initialized = false;
		std::vector<T>::const_iterator _iterator;
		std::vector<T> _vec;
	};
}