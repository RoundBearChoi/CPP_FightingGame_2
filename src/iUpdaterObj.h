#pragma once

namespace RB::Updaters
{
	class iUpdaterObj
	{
	public:
		iUpdaterObj() = default;
		virtual ~iUpdaterObj() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}
