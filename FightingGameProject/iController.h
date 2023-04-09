#pragma once

namespace RB::Controllers
{
	class iController
	{
	public:
		virtual ~iController() {};

	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}