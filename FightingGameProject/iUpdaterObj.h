#pragma once

namespace RB::Engine
{
	class iUpdaterObj
	{
	public:
		virtual ~iUpdaterObj() {};

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}