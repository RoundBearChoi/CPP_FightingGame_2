#pragma once

namespace RB::Controllers
{
	class iController
	{
	public:
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}