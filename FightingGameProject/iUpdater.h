#pragma once

namespace RB::Engine
{
	class iUpdater
	{
	public:
		virtual ~iUpdater() {};

		virtual void OnUpdate() = 0;
	};
}