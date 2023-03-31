#pragma once

namespace RB::Engine
{
	class iUpdater
	{
	public:
		virtual ~iUpdater() {};

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
	};
}