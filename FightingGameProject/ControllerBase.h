#pragma once
#include <string>

using namespace std;

namespace RB::Controllers
{
	class ControllerBase
	{
	public:
		virtual ~ControllerBase() {};

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		//void SetName(string name);
		//string GetName();

	//protected:
	//	string _name = "unnamed controller";
	};
}