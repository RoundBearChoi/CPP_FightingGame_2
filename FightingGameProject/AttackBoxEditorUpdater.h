#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class AttackBoxEditorUpdater : public iUpdaterObj
	{
	public:
		AttackBoxEditorUpdater() = default;
		~AttackBoxEditorUpdater() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}