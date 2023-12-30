#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class HurtBoxEditorUpdater : public iUpdaterObj
	{
		public:
			HurtBoxEditorUpdater() = default;
			~HurtBoxEditorUpdater() override;

			void Init();
			void OnUpdate();
			void OnFixedUpdate();
	};
}