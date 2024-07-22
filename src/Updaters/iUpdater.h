#pragma once

namespace RB::Updaters
{
	class iUpdater
	{
	public:
		virtual ~iUpdater() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		
		virtual bool QueueAttackBoxEditorUpdater() = 0;
		virtual bool QueueTargetBoxEditorUpdater() = 0;
	};
}
