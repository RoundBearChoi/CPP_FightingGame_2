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
		void OnFixedUpdate();
		void InitSelector_ToBegin(T begin);
		void InitSelector_ToRBegin(T rbegin);

	private:
		bool _fixedUpdated = false;
		bool _selectorInitialized = false;
		std::vector<T>::const_iterator _iterator;
	};
}