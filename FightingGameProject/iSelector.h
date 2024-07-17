#pragma once

#include <vector>

namespace RB
{
	template<class T>
	class iSelector
	{
	public:
		virtual ~iSelector() {}

		virtual void OnFixedUpdate() = 0;
		virtual void OnUpdate() = 0;
		virtual const std::vector<T>& GetVector() = 0;
		virtual std::vector<T>* GetVector_ptr() = 0;
		virtual void PushBack(T t) = 0;
		virtual void EraseSelected() = 0;
		virtual void EraseByIndex(unsigned int index) = 0;
		virtual T* GetSelected() = 0;
		virtual T* GetByIndex(unsigned int index) = 0;
		virtual void SelectUp() = 0;
		virtual void SelectDown() = 0;
		virtual bool IsEmpty() = 0;
		virtual void SetRefreshed(bool refreshed) = 0;
	};
}
