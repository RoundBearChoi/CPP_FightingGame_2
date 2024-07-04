#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class TargetBoxEditorUpdater : public iUpdaterObj
	{
		public:
			TargetBoxEditorUpdater() = default;
			~TargetBoxEditorUpdater() override;

			void Init();
			void OnUpdate();
			void OnFixedUpdate();
	};
}
