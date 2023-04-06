#pragma once
#include <string>

using namespace std;

namespace RB::Controllers
{
	class ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		string GetName();

	protected:
		string _name;

		void _SetName(string name);
	};
}