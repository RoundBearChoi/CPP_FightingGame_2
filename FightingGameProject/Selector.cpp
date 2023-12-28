#include "Selector.h"

namespace RB
{
	template<class T>
	void Selector<T>::OnFixedUpdate()
	{
		_fixedUpdated = true;
	}

	template<class T>
	void Selector<T>::InitSelector_ToBegin(T begin)
	{
		_iterator = begin;
		_selectorInitialized = true;
	}

	template<class T>
	void Selector<T>::InitSelector_ToRBegin(T rbegin)
	{
		_iterator = rbegin;
		_selectorInitialized = true;
	}
}