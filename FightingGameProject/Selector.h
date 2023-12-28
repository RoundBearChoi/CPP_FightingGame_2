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
			//_fixedUpdated = true;
		}

	private:
		bool _fixedUpdated = false;
		bool _initialized = false;
		std::vector<T>::const_iterator _iterator;
	};
}