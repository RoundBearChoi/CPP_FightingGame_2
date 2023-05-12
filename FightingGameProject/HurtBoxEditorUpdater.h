#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "ActiveControllers.h"
#include "CamController.h"
#include "MenuController.h"

namespace RB::Updaters
{
	class HurtBoxEditorUpdater : public iUpdaterObj
	{
		public:
			HurtBoxEditorUpdater();
			~HurtBoxEditorUpdater() override;

			void Init();
			void OnUpdate();
			void OnFixedUpdate();
	};
}