#pragma once

namespace RB::Updaters
{
	class iUpdater
	{
	public:
		virtual bool QueueAttackBoxEditorUpdater() = 0;
		virtual bool QueueTargetBoxEditorUpdater() = 0;
	};
}
