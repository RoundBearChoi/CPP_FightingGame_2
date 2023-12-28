#pragma once
#include <vector>

namespace RB
{
	template<class T>
	class Selector
	{
	public:
		Selector() = default;
		~Selector() = default;

	public:
		void OnFixedUpdate()
		{
			_fixedUpdated = true;
		}

		void InitSelector_ToBegin(T begin)
		{
			_iterator = begin;
			_selectorInitialized = true;
		}

		void InitSelector_ToRBegin(T rbegin)
		{
			_iterator = rbegin;
			_selectorInitialized = true;
		}

	private:
		bool _fixedUpdated = false;
		bool _selectorInitialized = false;
		std::vector<T>::const_iterator _iterator;
	};
}