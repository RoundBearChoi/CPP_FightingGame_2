#pragma once

#include "iUpdater.h"

namespace RB::Updaters
{
	class iPlayground
	{
	public:
		virtual ~iPlayground() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual void SetFixedUpdateSkips(int skips) = 0;
		virtual void ClearFixedUpdateSkip(int fixedUpdates) = 0;
		virtual bool QueueAttackBoxEditorUpdater() = 0;
		virtual bool QueueTargetBoxEditorUpdater() = 0;
		virtual iUpdater* GetUpdater() = 0;
	};
}