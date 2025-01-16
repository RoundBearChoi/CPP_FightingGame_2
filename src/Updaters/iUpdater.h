#pragma once

namespace RB::Updaters
{
	class iUpdater
	{
	public:
		iUpdater() = default;
		virtual ~iUpdater() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}