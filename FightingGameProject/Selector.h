#pragma once
#include <vector>

namespace RB
{
	template<class T>
	class Selector
	{
	public:
		Selector(std::vector<T>& vec)
		{
			_vec = &vec;
		}

		~Selector()
		{

		}

	public:
		void OnFixedUpdate()
		{
			//_fixedUpdated = true;
		}

	private:
		bool _fixedUpdated = false;
		bool _initialized = false;
		std::vector<T>::const_iterator _iterator;
		std::vector<T>* _vec = nullptr;
	};
}