#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class HitBoxEditorUpdater : public iUpdaterObj
	{
	public:
		HitBoxEditorUpdater() = default;
		~HitBoxEditorUpdater() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}