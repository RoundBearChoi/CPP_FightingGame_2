#pragma once

namespace RB::Updaters
{
	class iUpdater
	{
	public:
		virtual bool QueueTargetBoxEditorUpdater() = 0;
	};

	static iUpdater* ptrCurrentUpdater;
}
